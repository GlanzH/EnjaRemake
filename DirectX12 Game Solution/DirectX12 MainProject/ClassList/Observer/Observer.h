#pragma once

#include"ClassList/Base.h"

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

};
