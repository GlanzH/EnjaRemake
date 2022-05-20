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
	//�ړ�����
	void Player_limit();
	DX9::SKINNEDMODEL& GetModel() {return player; }

private:
	DX9::SKINNEDMODEL player;
	SimpleMath::Vector3 player_pos = SimpleMath::Vector3(0.0f, 0.0f, 50.0f);
	float model_scale = 0.25f;
	float model_rotetion;

	float player_speed;
	//�W�����v���Ă邩�̃t���O
	bool jump_flag_;
	float jump_time_;
	float jump_start_v_;
	//�W�����v�^�C�~���O
	bool  jump_start_flag;
	float jump_start_time;
	float jump_start_time_max;
	bool jump_end_flag;
	//1/2
	const float half = 0.5f;
	//�d�͉����x
	const float gravity_ = 170.0f;
	//����
	const float V0 = 70.5f;

	float upper_start;
	float upper_end;
	//�q�b�g�X�g�b�v�𔭓�������t���O
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
	//��i(�ϐ��錾)
	enum Upper_State
	{
		NOT_UPPER,
		UPPER_ATTACK
	};
	Upper_State upper_state_mode;
	//�v���C���[�̈ړ�����(��)
	const float model_collision_detection_X = 67.0f;
	const float model_collision_detection_Y_MAX = 1100.0f;
	const float model_collision_detection_Y_MIN = 0.0f;
	const float model_collision_detection_Z = 100.0f;
};
