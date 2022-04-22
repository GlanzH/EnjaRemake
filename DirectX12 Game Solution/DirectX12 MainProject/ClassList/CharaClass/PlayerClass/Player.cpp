#include "Player.h"



Player::Player(){
	player_speed = 0.0f;
	//ジャンプしてるかのフラグ
	jump_flag_ = false;
	jump_time_ = 0.0f;
	 model_rotetion =-90.0f;
	//jump_start_v_ = 0.0f;
}

bool Player::Initialize(){
	player_speed = 35.0f;
	//ジャンプしてるかのフラグ
	jump_flag_ = false;
	jump_time_ = 0.0f;
	jump_start_v_ = 0.0f;
	//ジャンプタイミング
	jump_start_flag = false;
	jump_start_time = 0.0f;
	jump_start_time_max = 0.000001f;
	jump_end_flag = false;
	return false;
}

void Player::LoadAseets()
{
	player = DX9::SkinnedModel::CreateFromFile(DXTK->Device9, L"Model//Player//new_olivia_.X");
	player->SetScale(0.25f);
	player->SetPosition(player_pos);
	player->SetRotation(0.0f,DirectX::XMConvertToRadians(model_rotetion),0.0f);
}

int Player::Update(const float deltaTime){
	PlayerAnimation(player, STAND);
	//Player移動
	Move(deltaTime);

	return 0;
}

void Player::Move(const float deltaTime){
	if (DXTK->KeyState->Right || DXTK->GamePadState[0].dpad.right || DXTK->GamePadState->thumbSticks.leftX > 0){
		player->Move(0.0f, 0.0f, -player_speed * deltaTime);
		player->SetRotation(0.0f, DirectX::XMConvertToRadians(model_rotetion),0.0f);
		PlayerAnimation(player, RUN);
	}
	if (DXTK->KeyState->Left || DXTK->GamePadState[0].dpad.left || DXTK->GamePadState->thumbSticks.leftX < 0){
		player->Move(0.0f, 0.0f, -player_speed * deltaTime);
		player->SetRotation(0.0f, DirectX::XMConvertToRadians(-model_rotetion), 0.0f);
		PlayerAnimation(player, RUN);
	}
	if (!jump_flag_){
		if (DXTK->KeyState->Up || DXTK->GamePadEvent->a == GamePad::ButtonStateTracker::PRESSED){
			jump_flag_ = true;
			jump_time_ = 0.0f;
			jump_start_v_ = player->Position.y;
		}
	}
	if (jump_flag_){
		jump_time_ += deltaTime;
		auto pos = player->GetPosition();
		PlayerAnimation(player, JUMP);
		pos.y = jump_start_v_ + V0 * jump_time_ - 0.5f * gravity_ * jump_time_ * jump_time_;
		player->SetPosition(pos);
		if (player->GetPosition().y <= 0.65f) {
			jump_flag_ = false;
			player->SetTrackPosition(JUMP, 0.0);
		}
	}
}

void Player::PlayerAnimation(DX9::SKINNEDMODEL& player, const int enableTrack){
	for (int i = 0; i < MOTION_MAX; ++i) {
		player->SetTrackEnable(i, FALSE);
	}
	player->SetTrackEnable(enableTrack, TRUE);
}

void Player::Render(){
	player->Draw();
}
