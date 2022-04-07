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
	int Update(const float deltaTime);
	void Move(const float deltaTime);
	void Render();

private:
	DX9::SKINNEDMODEL player;

	float player_speed;
	SimpleMath::Vector3 player_pos = SimpleMath::Vector3(0.0f, 0.0f, 50.0f);
	float model_scale = 0.25f;
	float model_rotetion = -90.0f;
	//ジャンプしてるかのフラグ
	bool jump_flag_;
	float jump_time_;
	float jump_start_v_;
};
