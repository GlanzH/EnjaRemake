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

	//プレイヤーの移動制限(幅)
	const float model_collision_detection_X = 67.0f;
	const float model_collision_detection_Y_MAX = 1000.0f;
	const float model_collision_detection_Y_MIN = 0.1f;
	const float model_collision_detection_Z = 100.0f;

	//当たり判定モデルの大きさ
	const int player_box_size_x = 0.1;
	const int player_box_size_y = 2;
	const int player_box_size_z = 1;

	const int box_size_x = 3.5;
	const int box_size_y = 2;
	const int box_size_z = 4;

	const int sidebox_size_x = 2;
	const int sidebox_size_y = 9;
	const int sidebox_size_z = 1;
	//無敵時間
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

	//ダメージ受けた時
	bool damage_flag;

	int damage_se_count = 0;
	

	//『使用しない』****************************//
		//アピール
	bool appeil_flag;
	float appeil_time;
	bool appeil_cool_flag;
	//必殺技
	bool deathbrow_flag;//必殺技発動フラグ
//*****************************************//

	//SE 変数
	//攻撃-SE
	XAudio::SOUNDEFFECT  attack_se;

	//攻撃が弾かれる　SE
	XAudio::SOUNDEFFECT frip_se;

	//ダメージ SE
	XAudio::SOUNDEFFECT damage_se;

	//止め SE
	XAudio::SOUNDEFFECT stop_se;

	//************************************//


	//回避
	bool  avoidance_flag;
	float avoidance_start;
	float avoidance_max;
	float avoidance_move;


	

	//ノックバック
	void Knock_back_Move();

	bool knock_back_flag;
	float knock_back_start;
	float knock_back_end;
	float time_other;

	//起き上がる
	void Rize();

	float rize_end;

	enum Damage_Mode
	{
		NOMAL_STATE, //通常状態
		KNOCK_BACK   //ノックバック
	};
	Damage_Mode damage_mode_state;

	//ノックバックする方向
	enum Direction_Knock_Back
	{
		RIGHT_BACK,
		LEFT_BACK
	};

	Direction_Knock_Back direction_knock_back;

	//上段(変数宣言)
	enum Upper_State
	{
		NOT_UPPER,
		UPPER_ATTACK
	};
	Upper_State upper_state_mode;
	float upper_start;
	float upper_end;

	//下段(変数宣言)
	enum Lower_State
	{
		NOT_LOWER,
		LOWER_ATTACK
	};
	Lower_State lower_state_mode;
	float lower_start;
	float lower_end;

	//ヒットストップを発動させるフラグ
	bool hit_stop_flag;

	//納刀
	void Sword_Delivery(const float deltaTime, bool temp);
	bool  s_del_flag;
	float s_del_start;
	float s_del_end;

	int s_del_count = 0;

	//敵の消滅
	bool elimination_flag;
	float elimination_end;

	//弾く
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

	//プレイヤーの移動スピード変動
	void Speed_Step(const float deltaTime);

	int point = 0;

	bool step_up_flag = false;

	float stepup_start = 0.0f;
};


	