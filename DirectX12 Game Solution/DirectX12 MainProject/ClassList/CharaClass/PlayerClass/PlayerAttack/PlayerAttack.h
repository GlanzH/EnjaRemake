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
	//UŒ‚‚ÌŠÔ
	bool  attack_flag;
	float attack_time;
	float attack_zeit_max;
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