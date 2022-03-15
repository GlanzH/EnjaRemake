#pragma once

#include"Base/pch.h"
#include"Base/dxtk.h"
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





