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
	void Attack();
	void Frip();
	
private:
	//UŒ‚‚ÌŠÔ
	bool  attack_flag;
	float attack_time;
	float attack_zeit_max;
	//“–‚½‚è”»’è—pƒ‚ƒfƒ‹
	DX9::MODEL sword_collision;
	DX9::MODEL collision;
	Collisions col;

	DX9::MODEL right_collision;
	Collisions right_col;
	DX9::MODEL left_collision;
	Collisions left_col;

	D3DMATERIAL9 material;
	//UŒ‚’†@ƒWƒƒƒ“ƒv•s‰Â
	enum UNDER_ATTACK_STATE
	{
		NOMAL,
		ATTACK
	};
	UNDER_ATTACK_STATE under_attack_state_mode;
	//UŒ‚‚ÌŒü‚«
	enum Direction_State
	{
		LEFT,
		RIGHT
	};

	Direction_State direction_state_mode;
	//UŒ‚‚Ìí—Ş 1:ãUŒ‚@2:“Ë‚«UŒ‚
	int attack_type;
};