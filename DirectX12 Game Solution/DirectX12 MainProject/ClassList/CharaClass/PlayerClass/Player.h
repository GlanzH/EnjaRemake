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
	void Attack(const float deltaTime);
	void SetAnimation(DX9::SKINNEDMODEL& player, const int enableTrack);
	void Render();
	//移動制限
	void Player_limit();
	DX9::SKINNEDMODEL& GetModel() {return player; }

private:
	DX9::SKINNEDMODEL player;
	SimpleMath::Vector3 player_pos = SimpleMath::Vector3(0.0f, 0.0f, 50.0f);
	float model_scale = 0.25f;
	float model_rotetion;

	float player_speed;
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

	float upper_start;
	float upper_end;
	//ヒットストップを発動させるフラグ
	bool hit_stop_flag;
	enum
	{
		STAND,
		RUN,
		ACT1,
		FINISH,
		REBOUND,
		DAMAGE1,
		ROLL,
		JUMP,
		MOTION_MAX
	};
	//上段(変数宣言)
	enum Upper_State
	{
		NOT_UPPER,
		UPPER_ATTACK
	};
	Upper_State upper_state_mode;
	//プレイヤーの移動制限(幅)
	const float model_collision_detection_X = 67.0f;
	const float model_collision_detection_Y_MAX = 1100.0f;
	const float model_collision_detection_Y_MIN = 0.0f;
	const float model_collision_detection_Z = 100.0f;
};
