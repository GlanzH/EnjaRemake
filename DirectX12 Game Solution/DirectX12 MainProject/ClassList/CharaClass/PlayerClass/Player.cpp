#include "Player.h"
#include"ClassList/StatusManager/StatusManager.h"
Player::Player(){
	player_speed = 0.0f;
	//ジャンプしてるかのフラグ
	jump_flag_ = false;
	jump_time_ = 0.0f;
	 model_rotetion =-90.0f;
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
	/*upper_start = 0.0f;
	upper_end = 0.383f;*/
	return false;
}

void Player::LoadAseets()
{
	player = DX9::SkinnedModel::CreateFromFile(DXTK->Device9, L"Model//Player//new_olivia_.X");
	player->SetScale(0.25f);
	player->SetPosition(player_pos);
	player->SetRotation(0.0f,DirectX::XMConvertToRadians(model_rotetion),0.0f);
}


void Player::SetAnimation(DX9::SKINNEDMODEL& player, const int enableTrack) {
	for (int i = 0; i < MOTION_MAX; ++i) {
		player->SetTrackEnable(i, FALSE);
	}
	player->SetTrackEnable(enableTrack, TRUE);
}

int Player::Update(const float deltaTime){
	SetAnimation(player, STAND);
	//Player移動
	Move(deltaTime);
	//Player攻撃
	Attack(deltaTime);
	Player_limit();
	player->AdvanceTime(deltaTime);
	return 0;
}

void Player::Move(const float deltaTime){
	if (DXTK->KeyState->Right || DXTK->GamePadState[0].dpad.right || DXTK->GamePadState->thumbSticks.leftX > 0){
		player->Move(0.0f, 0.0f, -player_speed * deltaTime);
		player->SetRotation(0.0f, DirectX::XMConvertToRadians(model_rotetion),0.0f);
		SetAnimation(player, RUN);
	}

	if (DXTK->KeyState->Left || DXTK->GamePadState[0].dpad.left || DXTK->GamePadState->thumbSticks.leftX < 0){
		player->Move(0.0f, 0.0f, -player_speed * deltaTime);
		player->SetRotation(0.0f, DirectX::XMConvertToRadians(-model_rotetion), 0.0f);
		SetAnimation(player, RUN);
	}

	if (!jump_flag_){
		if (DXTK->KeyEvent->pressed.Up || DXTK->GamePadEvent->a == GamePad::ButtonStateTracker::PRESSED){
			jump_flag_ = true;
			jump_time_ = 0.0f;
			jump_start_v_ = player->Position.y;
		}
	}

	if (jump_flag_){
		jump_time_ += deltaTime;
		auto pos = player->GetPosition();
		SetAnimation(player, JUMP);
		pos.y = jump_start_v_ + V0 * jump_time_ - 0.5f * gravity_ * jump_time_ * jump_time_;
		player->SetPosition(pos);
		if (player->GetPosition().y <= 0.65f) {
			jump_flag_ = false;
			player->SetTrackPosition(JUMP, 0.0);
		}
	}
}

void Player::Attack(const float deltaTime)
{
	if (!jump_flag_)
	{
		if (DXTK->KeyEvent->pressed.A || DXTK->GamePadEvent[0].y == GamePad::ButtonStateTracker::PRESSED)
		{
			//upper_state_mode = Upper_State::UPPER_ATTACK;
		}
		//if(upper_state_mode ==Upper_State::UPPER_ATTACK)
		/*{
			SetAnimation(player, ACT1);
			if (true)
			{

			}
		}*/
	}
}
void Player::Render(){
	player->Draw();
}

void Player::Player_limit()
{
	//移動制限
	auto p_pos = player->GetPosition();
	p_pos = SimpleMath::Vector3(
		std::clamp(p_pos.x, -model_collision_detection_X, model_collision_detection_X),
		std::clamp(p_pos.y, model_collision_detection_Y_MIN, model_collision_detection_Y_MAX),
		std::clamp(p_pos.z, -model_collision_detection_Z, model_collision_detection_Z)
	);
	player->SetPosition(p_pos);
}
