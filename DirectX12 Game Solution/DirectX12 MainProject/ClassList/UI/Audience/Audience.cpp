#include "ClassList/UI/Audience/Audience.h"

Audience::Audience() {
	audience_normal	   = nullptr;
	audience_hard	   = nullptr;
	audience_very_hard = nullptr;
	audience_state = 0;
}

void Audience::Intialize() {
	audience_state = NORMAL;
}

void Audience::LoadAseets() {
	audience_normal	   = DX9::Sprite::CreateFromFile(DXTK->Device9, L"UI/Audience/hyouka1.png");
	audience_hard	   = DX9::Sprite::CreateFromFile(DXTK->Device9, L"UI/Audience/hyouka2.png");
	audience_very_hard = DX9::Sprite::CreateFromFile(DXTK->Device9, L"UI/Audience/hyouka3.png");
}

void Audience::Update() {

}

void Audience::Render() {
	switch (audience_state)
	{
	case NORMAL:
		DX9::SpriteBatch->DrawSimple(
			audience_normal.Get(),
			SimpleMath::Vector3(0.0f, 0.0f, 0.0f),
			RectWH(0, 0, 1388, 180)
		);
		break;
	case HARD:

		break;

	case VERY_HARD:

		break;
	}
}