#pragma once

#include"ClassList/Base.h"

using namespace DirectX;

class PlayerBase : public Base
{
public:
	PlayerBase() {};
	~PlayerBase() {};
	bool Initialize();
	void LoadAssets();
	int Update();
	void Render();

private:
	D3DMATERIAL9 material;

	int damage = 0;
	int reduce_num = 0;

	const int body_reduce_num = -20;
	const int weapon_reduce_num = -40;

	const int mb_reduce_num = -30;
	const int mb_weapon_reduce_num = -60;

	//�v���C���[�̈ړ�����(��)
	const float model_collision_detection_X = 67.0f;
	const float model_collision_detection_Y_MAX = 1000.0f;
	const float model_collision_detection_Y_MIN = 0.1f;
	const float model_collision_detection_Z = 100.0f;

	//�����蔻�胂�f���̑傫��
	const int player_box_size_x = 0.1;
	const int player_box_size_y = 2;
	const int player_box_size_z = 1;

	const int box_size_x = 3.5;
	const int box_size_y = 2;
	const int box_size_z = 4;

	const int sidebox_size_x = 2;
	const int sidebox_size_y = 9;
	const int sidebox_size_z = 1;
	//���G����
	bool        invincible_flag;
	float		invincible_time;
	float       invincible_time_max;

	enum Invincible_Type
	{
		NOT_INVICIBLE,
		AVOIDANCE_INV,
		KNOCK_BACK_INV,
		FRIP_INV
	};

	Invincible_Type invincible_type;

	//�_���[�W�󂯂���
	bool damage_flag;

	int damage_se_count = 0;
	

	//�w�g�p���Ȃ��x****************************//
		//�A�s�[��
	bool appeil_flag;
	float appeil_time;
	bool appeil_cool_flag;
	//�K�E�Z
	bool deathbrow_flag;//�K�E�Z�����t���O
//*****************************************//

	//SE �ϐ�
	//�U��-SE
	XAudio::SOUNDEFFECT  attack_se;

	//�U�����e�����@SE
	XAudio::SOUNDEFFECT frip_se;

	//�_���[�W SE
	XAudio::SOUNDEFFECT damage_se;

	//�~�� SE
	XAudio::SOUNDEFFECT stop_se;

	//************************************//


	//���
	bool  avoidance_flag;
	float avoidance_start;
	float avoidance_max;
	float avoidance_move;


	

	//�m�b�N�o�b�N
	void Knock_back_Move();

	bool knock_back_flag;
	float knock_back_start;
	float knock_back_end;
	float time_other;

	//�N���オ��
	void Rize();

	float rize_end;

	enum Damage_Mode
	{
		NOMAL_STATE, //�ʏ���
		KNOCK_BACK   //�m�b�N�o�b�N
	};
	Damage_Mode damage_mode_state;

	//�m�b�N�o�b�N�������
	enum Direction_Knock_Back
	{
		RIGHT_BACK,
		LEFT_BACK
	};

	Direction_Knock_Back direction_knock_back;

	//��i(�ϐ��錾)
	enum Upper_State
	{
		NOT_UPPER,
		UPPER_ATTACK
	};
	Upper_State upper_state_mode;
	float upper_start;
	float upper_end;

	//���i(�ϐ��錾)
	enum Lower_State
	{
		NOT_LOWER,
		LOWER_ATTACK
	};
	Lower_State lower_state_mode;
	float lower_start;
	float lower_end;

	//�q�b�g�X�g�b�v�𔭓�������t���O
	bool hit_stop_flag;

	//�[��
	void Sword_Delivery(const float deltaTime, bool temp);
	bool  s_del_flag;
	float s_del_start;
	float s_del_end;

	int s_del_count = 0;

	//�G�̏���
	bool elimination_flag;
	float elimination_end;

	//�e��
	enum Frip_State
	{
		NOT_FRIP,
		FRIP
	};

	Frip_State frip_state_mode;

	bool frip_flag;

	void Frip_Knock_Back();
	float frip_start = 0.0f;
	float frip_end = 0.783f;

	int frip_se_count = 0;

	int effect_count = 0;

	//�v���C���[�̈ړ��X�s�[�h�ϓ�
	void Speed_Step(const float deltaTime);

	int point = 0;

	bool step_up_flag = false;

	float stepup_start = 0.0f;
};


	