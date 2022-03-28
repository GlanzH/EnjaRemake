#pragma once
#include "Base/pch.h"
#include "Base/dxtk.h"

using namespace DirectX;

class Combo {
public:

	void Initialize();
	void LoadAssets();
	void Update(const float deltaTime);
	void Render();

	static Combo& Instance() {
		static Combo instance;
		return instance;
	}

	void AddCombo();
	void ResetCombo();
	int GetCombo() { return combo; }
	float GetComboTime() { return combo_time; }

private:
	Combo();

	void AddComboTime();
	void ComboTimeCount();
	bool IsComboTimeZero() { return combo_time <= 0.0f; }
	bool IsComboContinuing() { return combo > 0; }

	int combo;
	float time_delta;
	float combo_time;
	bool combo_time_stop_flag;

	const float MAX_TIME = 6.0f;
	const float MIN_TIME = 3.0f;

	//コンボUI関連
	void ResetAnimeFrame();
	int ComboBalloonHight();
	int ComboOneDigit();
	int ComboTwoDigit();
	int ComboGaugeWidth();
	float ComboAnimation();
	bool IsComboTimeContinuing() { return combo_time > 0.0f; }
	bool IsComboAnimationPlaying() { return combo_anime_frame > 0.0f; }
	bool IsAnimationEnd() { return combo_anime_frame > MAX_ANIME_FRAME; }
	bool IsComboTwoDigit() { return combo >= 10; }

	DX9::SPRITE combo_balloon;
	DX9::SPRITE combo_text;
	DX9::SPRITE combo_number;
	DX9::SPRITE combo_gauge;

	int combo_balloon_hight;
	float combo_anime_frame;
	bool combo_anime_play_flag;

	const int COMBO_BALLOON_WIDTH	  = 331;
	const int COMBO_BALLOON_MIN_HIGHT = 232;
	const int COMBO_NUMBER_WIDTH = 48;
	const int COMBO_NUMBER_HIGHT = 60;
	const int COMBO_GAUGE_HIGHT = 10;

	const float COMBO_BALLOON_POS_X = 950.0f;
	const float COMBO_BALLOON_POS_Y = 500.0f;
	const float COMBO_BALLOON_POS_Z = 1.0f;
	const float ANIMATION_SPEED = 30.0f;
	const float MAX_ANIME_FRAME = 9.0f;
	const float COMBO_TEXT_POS_X = COMBO_BALLOON_POS_X + 140.0f;
	const float COMBO_TEXT_POS_Y = COMBO_BALLOON_POS_Y + 100.0f;
	const float COMBO_ONE_DIGIT_POS_X = COMBO_BALLOON_POS_X + 90.0f;
	const float COMBO_ONE_DIGIT_POS_Y = COMBO_BALLOON_POS_Y + 70.0f;
	const float COMBO_TWO_DIGIT_POS_X = COMBO_BALLOON_POS_X + 50.0f;
	const float COMBO_TWO_DIGIT_POS_Y = COMBO_BALLOON_POS_Y + 70.0f;
	const float COMBO_GAUGE_POS_X  = COMBO_BALLOON_POS_X + 80.0f;
	const float COMBO_GAUGE_POS_Y  = COMBO_BALLOON_POS_Y + 130.0f;
	const float COMBO_GAUGE_DIVIDE = 28.5f;	//コンボゲージ6分の1の数(描画時使用)
};