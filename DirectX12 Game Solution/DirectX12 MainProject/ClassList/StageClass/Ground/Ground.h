#pragma once

#include"Base/pch.h"
#include"Base/dxtk.h"

using namespace DirectX;

class Ground
{
public:
	Ground(){};
	~Ground(){};
	void LoadAseets();
	int Update();
	void Render();
private:
	DX9::MODEL forest;


};