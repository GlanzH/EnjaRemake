#pragma once

#include"ClassList/Base.h"

class PlayerManager : public Base
{
public:
	PlayerManager() {};
	~PlayerManager() {};
	bool Initialize();
	void LoadAssets();
	int Update();
	void Render();

private:

};
