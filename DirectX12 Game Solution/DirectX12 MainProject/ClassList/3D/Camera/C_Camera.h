#pragma once

#include"Base/pch.h"
#include"Base/dxtk.h"

using namespace DirectX;
class C_Camera
{
public:
	C_Camera(){};
	~C_Camera(){};

	bool Initialize();
	int Update();
	void Render();

private:
	DX9::CAMERA camera;
	SimpleMath::Vector3 positsion;
    float camera_z = -10.0f;
	const float fixed_pos = 13.0f;
	const float rotate_angle = 40.0f;
	const float aspect = 16.0f / 9.0f;
	const float min_screen_range = 1.0f;
	const float max_screen_range = 10000.0f;
};