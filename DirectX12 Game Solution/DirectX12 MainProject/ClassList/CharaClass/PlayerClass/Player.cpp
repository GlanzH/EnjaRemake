#include "Player.h"



Player::Player()
{
	player_speed = 0.0f;
}

bool Player::Initialize()
{
	player_speed = 35.0f;
	return false;
}

void Player::LoadAseets()
{
	player = DX9::SkinnedModel::CreateFromFile(DXTK->Device9, L"Model//Player//new_olivia_.X");
}

int Player::Update()
{
	if (DXTK->KeyState->Right||DXTK->GamePadState[0].dpad.right||DXTK->GamePadState->thumbSticks.leftX > 0)
	{

	}
	if (DXTK->KeyState->Left||DXTK->GamePadState[0].dpad.left||DXTK->GamePadState->thumbSticks.leftX < 0)
	{

	}

	return 0;
}

void Player::Render()
{
}
