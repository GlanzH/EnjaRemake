#include "ClassList/UI/Audience/Audience.h"

Audience::Audience() {
	audience_normal	   = nullptr;
	audience_hard	   = nullptr;
	audience_very_hard = nullptr;
	audience_state = 0;
	audience_anime_frame = 0.0f;
	time_delta = 0.0f;
}

void Audience::Intialize() {
	audience_state = NORMAL;
	audience_anime_frame = 0.0f;
	time_delta = 0.0f;
}

void Audience::LoadAseets() {
	audience_normal	   = DX9::Sprite::CreateFromFile(DXTK->Device9, L"UI/Audience/hyouka1.png");
	audience_hard	   = DX9::Sprite::CreateFromFile(DXTK->Device9, L"UI/Audience/hyouka2.png");
	audience_very_hard = DX9::Sprite::CreateFromFile(DXTK->Device9, L"UI/Audience/hyouka3.png");
}

void Audience::Update(const float deltaTime) {
	time_delta = deltaTime;
}

void Audience::Render() {
	switch (audience_state)
	{
	case NORMAL:
		DX9::SpriteBatch->DrawSimple(
			audience_normal.Get(),
			SimpleMath::Vector3(0.0f, 0.0f, 0.0f),
			RectWH(0, AudienceHight(), 1388, AUDIENCE_MIN_HIGHT)
		);
		break;
	case HARD:

		break;

	case VERY_HARD:

		break;
	}
}

void Audience::SetAudienceState(int combo) {
	audience_state = combo;
}

float Audience::AudienceAnimation() {
	audience_anime_frame += ANIMATION_SPEED * time_delta;
	
	if (IsAnimationEnd()) {
		audience_anime_frame = 0.0f;
	}

	return audience_anime_frame;
}

int Audience::AudienceHight() {
	return AUDIENCE_MIN_HIGHT * (int)AudienceAnimation();
}
