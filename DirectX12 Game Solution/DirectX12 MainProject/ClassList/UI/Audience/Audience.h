#pragma once

#include "Base/pch.h"
#include "Base/dxtk.h"

using namespace DirectX;

class Audience {
public:
	~Audience() {};

	void Intialize();
	void LoadAseets();
	void Update(const float deltaTime);
	void Render();
	void SetAudienceState(int combo);
	static Audience& Instance() {
		static Audience instance;
		return instance;
	}
private:
	Audience();
	float AudienceAnimation();
	int AudienceHight();
	bool IsAnimationEnd() { return audience_anime_frame > 12; }
	DX9::SPRITE audience_normal;
	DX9::SPRITE audience_hard;
	DX9::SPRITE audience_very_hard;

	int audience_state;
	float audience_anime_frame;
	float time_delta;
	enum AUDIENCE_STATE {
		NORMAL,
		HARD,
		VERY_HARD
	};

	const int AUDIENCE_MIN_HIGHT = 180;
	const int ANIMATION_SPEED = 30;
};