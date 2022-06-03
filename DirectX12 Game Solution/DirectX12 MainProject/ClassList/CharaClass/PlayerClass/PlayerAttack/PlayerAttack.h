#include"Base/pch.h"
#include"Base/dxtk.h"

using namespace DirectX;

typedef struct Collisions {
	BoundingBox  sword_box;
	BoundingBox  box;

	BoundingBox right_box;
	BoundingBox left_box;

};

class PlayerAttack
{
public:
	PlayerAttack();
	~PlayerAttack(){};
	bool Initialize();
	void LoadAseets(DX9::SKINNEDMODEL model);
	int Update(DX9::SKINNEDMODEL model,const float deltaTime,SimpleMath::Vector3 pos);
	void Attack(const float deltaTime, DX9::SKINNEDMODEL model);
	void Frip();
	
private:
	//攻撃の時間
	bool  attack_flag;
	float attack_time;
	float attack_zeit_max;
	//当たり判定用モデル
	DX9::MODEL sword_collision;
	DX9::MODEL collision;
	Collisions col;

	DX9::MODEL right_collision;
	Collisions right_col;
	DX9::MODEL left_collision;
	Collisions left_col;

	D3DMATERIAL9 material;
	//攻撃中　ジャンプ不可
	enum UNDER_ATTACK_STATE
	{
		NOMAL,
		ATTACK
	};
	UNDER_ATTACK_STATE under_attack_state_mode;
	//攻撃の向き
	enum Direction_State
	{
		LEFT,
		RIGHT
	};
	Direction_State direction_state_mode;
	//上段(変数宣言)
	enum Upper_State
	{
		NOT_UPPER,
		UPPER_ATTACK
	};
	Upper_State upper_state_mode;
	//攻撃の種類 1:弱攻撃　2:突き攻撃
	int attack_type;



	float upper_start;
	float upper_end;
	//ヒットストップを発動させるフラグ
	bool hit_stop_flag;
};