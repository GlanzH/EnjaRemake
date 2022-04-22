#pragma once

#include"Base/pch.h"
#include"Base/dxtk.h"
#include"ClassList/CharaClass/PlayerClass/Player.h"

using namespace DirectX;
class C_Camera
{
public:
	C_Camera(){};
	~C_Camera(){};

	bool Initialize();
	int Update(Player* player,const float deltaTime);
	void Render();

private:
	DX9::CAMERA camera;
	SimpleMath::Vector3 positsion;


	enum CAMERAMODE
	{
		ZOOM_UP,
		ZOOM_OUT
	};
    float camera_z = -10.0f;

	const float positsion_y = 30.0f;
	const float fixed_pos = 13.0f;

	const float rotate_angle = 40.0f;
	const float aspect = 16.0f / 9.0f;

	const float min_screen_range = 1.0f;
	const float max_screen_range = 10000.0f;
};