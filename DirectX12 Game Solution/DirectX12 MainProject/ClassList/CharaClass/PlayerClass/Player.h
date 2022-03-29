#pragma once

#include"ClassList/CharaClass/PlayerClass/PlayerBase/PlayerBase.h"
using namespace DirectX;

class Player :public PlayerBase
{
public:
	Player() ;
	~Player(){};
	bool Initialize();
	void LoadAseets();
	int Update();
	void Render();

private:
	DX9::SKINNEDMODEL player;

	float player_speed;
};
