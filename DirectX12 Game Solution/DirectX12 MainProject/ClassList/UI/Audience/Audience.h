#pragma once

#include "Base/pch.h"
#include "Base/dxtk.h"

using namespace DirectX;

class Audience {
public:
	~Audience() {};

	void Intialize();
	void LoadAseets();
	void Update();
	void Render();

	static Audience& Instance() {
		static Audience instance;
		return instance;
	}
private:
	Audience();
	DX9::SPRITE audience_normal;
	DX9::SPRITE audience_hard;
	DX9::SPRITE audience_very_hard;

	int audience_state;
	enum AUDIENCE_STATE {
		NORMAL,
		HARD,
		VERY_HARD
	};
};