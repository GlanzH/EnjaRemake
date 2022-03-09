#pragma once

#include"Base/dxtk.h"
#include"Base/pch.h"

using namespace DirectX;

class Base
{
public:
	Base(){};
	~Base(){};
	bool Initialize();
	void LoadAssets();
	int Update();
	void Render();
private:

};





