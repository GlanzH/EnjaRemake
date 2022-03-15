#include"C_Camera.h"

bool C_Camera::Initialize()
{
	//カメラの位置
	camera->SetView(SimpleMath::Vector3(0.0,fixed_pos, 20.0), SimpleMath::Vector3::Zero);
	//カメラの向き・映す距離		//角度、側面
	camera->SetPerspectiveFieldOfView(XMConvertToRadians(rotate_angle),aspect,min_screen_range,max_screen_range);
	return false;
}

int C_Camera::Update()
{
	camera_z = std::clamp(camera_z, -10.0f,20.0f);

	//camera->SetPosition(base->GetModel()->GetPosition().x, fixed_pos, -camera_z);
	SimpleMath::Vector3 camera_pos = camera.GetPosition();
	if (camera_pos.x >= 40.0f) {
		camera_pos.x = 40.0f;
		camera->SetPosition(camera_pos);
	}
	if (camera_pos.x <= -40.0f) {
		camera_pos.x = -40.0f;
		camera->SetPosition(camera_pos);
	}
	return 0;
}

void C_Camera::Render()
{
	DXTK->Direct3D9->SetCamera(camera);
}
