#include"Base/pch.h"
#include"Base/dxtk.h"


class PlayerAttack
{
public:
	PlayerAttack();
	~PlayerAttack(){};
	bool Initialize();
	int Update();
	
private:
	//�U���̎���
	bool  attack_flag;
	float attack_time;
	float attack_zeit_max;
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