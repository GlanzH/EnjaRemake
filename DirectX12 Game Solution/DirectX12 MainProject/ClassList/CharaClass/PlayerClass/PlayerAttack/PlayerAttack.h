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
	//�U���̎���
	bool  attack_flag;
	float attack_time;
	float attack_zeit_max;
	//�����蔻��p���f��
	DX9::MODEL sword_collision;
	DX9::MODEL collision;
	Collisions col;

	DX9::MODEL right_collision;
	Collisions right_col;
	DX9::MODEL left_collision;
	Collisions left_col;

	D3DMATERIAL9 material;
	//�U�����@�W�����v�s��
	enum UNDER_ATTACK_STATE
	{
		NOMAL,
		ATTACK
	};
	UNDER_ATTACK_STATE under_attack_state_mode;
	//�U���̌���
	enum Direction_State
	{
		LEFT,
		RIGHT
	};

	Direction_State direction_state_mode;
	//�U���̎�� 1:��U���@2:�˂��U��
	int attack_type;
};