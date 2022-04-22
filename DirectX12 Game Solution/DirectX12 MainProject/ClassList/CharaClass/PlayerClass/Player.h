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
	void PlayerAnimation(DX9::SKINNEDMODEL& player, const int enableTrack);
	void Render();
	DX9::SKINNEDMODEL& GetModel() {return player; }

private:
	DX9::SKINNEDMODEL player;

	float player_speed;
	SimpleMath::Vector3 player_pos = SimpleMath::Vector3(0.0f, 0.0f, 50.0f);
	float model_scale = 0.25f;
	float model_rotetion;
	//ジャンプしてるかのフラグ
	bool jump_flag_;
	float jump_time_;
	float jump_start_v_;
	//ジャンプタイミング
	bool  jump_start_flag;
	float jump_start_time;
	float jump_start_time_max;
	bool jump_end_flag;
	//1/2
	const float half = 0.5f;
	//重力加速度
	const float gravity_ = 170.0f;
	//初速
	const float V0 = 70.5f;
	/*enum
	{
		STAND,
		RUN,
		ACT1,
		ACT2,
		FINISH,
		REBOUND,
		JUMP,
		ROLL,
		DAMAGE1,
		MOTION_MAX
	};*/
	enum 
	{
		STAND,
		RUN,
		JUMP,
		MOTION_MAX
	};

};
