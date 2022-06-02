#include "PlayerAttack.h"

//bool PlayerAttack::Initialize()
//{
//    return false;
//}
//
//void PlayerAttack::LoadAseets(DX9::SKINNEDMODEL model)
//{
//	//‰E‚Ì“–‚½‚è”»’è
//	right_col.right_box = model->GetBoundingBox();
//	right_col.right_box.Extents = SimpleMath::Vector3(right_col.right_box.Extents) * 0.2f;
//	right_collision = DX9::Model::CreateBox(
//		DXTK->Device9,
//		right_col.right_box.Extents.x * 2,
//		right_col.right_box.Extents.y * 2,
//		right_col.right_box.Extents.z * 2
//	);
//	right_collision->SetMaterial(material);
//
//	//¶‚Ì“–‚½‚è”»’è
//	left_col.left_box = model->GetBoundingBox();
//	left_col.left_box.Extents = SimpleMath::Vector3(left_col.left_box.Extents) * 0.2f;
//	left_collision = DX9::Model::CreateBox(
//		DXTK->Device9,
//		left_col.left_box.Extents.x * 2,
//		left_col.left_box.Extents.y * 2,
//		left_col.left_box.Extents.z * 2
//	);
//	left_collision->SetMaterial(material);
//
//
//	col.sword_box = model->GetBoundingBox();
//	col.sword_box.Extents = SimpleMath::Vector3(col.sword_box.Extents) * 2.0f;
//	sword_collision = DX9::Model::CreateBox(
//		DXTK->Device9,
//		col.sword_box.Extents.x * 1,
//		col.sword_box.Extents.y * 1,
//		col.sword_box.Extents.z * 1
//	);
//	sword_collision->SetMaterial(material);
//}
//
//int PlayerAttack::Update(DX9::SKINNEDMODEL model, const float deltaTime,SimpleMath::Vector3 pos)
//{
//	//UŒ‚‚ÌŒü‚«
//	if (direction_state_mode == Direction_State::RIGHT) {
//		sword_collision->SetPosition(model->GetPosition() + SimpleMath::Vector3(6.5, 5, 0));
//		col.sword_box.Center = sword_collision->GetPosition() + SimpleMath::Vector3(0, -5.1, 0);
//	}
//	else if (direction_state_mode == Direction_State::LEFT) {
//
//		sword_collision->SetPosition(model->GetPosition() + SimpleMath::Vector3(-6.5, 5, 0));
//		col.sword_box.Center = sword_collision->GetPosition() + SimpleMath::Vector3(0, -5.1, 0);
//	}
//	//UŒ‚”»’è‚ÌŽžŠÔ
//	if (attack_flag)
//		attack_time += deltaTime;
//	if (attack_time >= attack_zeit_max) {
//		attack_flag = false;
//		attack_time = 0.0f;
//	}
//	right_collision->SetPosition(pos.x + 1.1f, pos.y + 5.0f,pos.z);
//	right_col.right_box.Center = right_collision->GetPosition() + SimpleMath::Vector3(0, -5.1, 0);
//
//	left_collision->SetPosition(pos.x - 1.1f, pos.y + 5.0f, pos.z);
//	left_col.left_box.Center = left_collision->GetPosition() + SimpleMath::Vector3(0, -5.1, 0);
//    return 0;
//}

void PlayerAttack::Attack(const float deltaTime, DX9::SKINNEDMODEL model)
{
	/*	upper_start += deltaTime;

		if (upper_start >= 0.1f) {
			hit_stop_flag = true;
		}
		
		if (upper_start >= upper_end) {
			upper_state_mode = Upper_State::NOT_UPPER;
			upper_start = 0.0f;
			model->SetTrackPosition(, 0.0);
			hit_stop_flag = false;
		}
	}*/
}
