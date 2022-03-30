#include "ClassList/StatusManager/Combo/Combo.h"

Combo::Combo() {
	combo	   = 0;
	time_delta = 0.0f;
	combo_time = 0.0f;
	combo_time_stop_flag = false;

	combo_balloon = nullptr;
	combo_text	  = nullptr;
	combo_number  = nullptr;
	combo_gauge	  = nullptr;

	combo_balloon_hight = 0;
	combo_anime_frame	= 0.0f;
	combo_anime_play_flag = false;
}

void Combo::Initialize() {
	combo	   = 0;
	time_delta = 0.0f;
	combo_time = 0.0f;
	combo_time_stop_flag = false;


	combo_balloon_hight = 0;
	combo_anime_frame	= 0.0f;
	combo_anime_play_flag = false;
}

void Combo::LoadAssets() {
	combo_balloon = DX9::Sprite::CreateFromFile(DXTK->Device9, L"UI/Combo/Combo_Anim.png"	  );
	combo_text	  = DX9::Sprite::CreateFromFile(DXTK->Device9, L"UI/Combo/COMBO.png"		  );
	combo_number  = DX9::Sprite::CreateFromFile(DXTK->Device9, L"UI/Combo/numbers_combo_h.png");
	combo_gauge	  = DX9::Sprite::CreateFromFile(DXTK->Device9, L"UI/Combo/combo_gauge.png"	  );
}

void Combo::Update(const float deltaTime) {
	time_delta = deltaTime;
	ComboTimeCount();
}

void Combo::Render() {
	if (IsComboTimeContinuing()) {
		DX9::SpriteBatch->DrawSimple(
		combo_balloon.Get(),
		SimpleMath::Vector3(COMBO_BALLOON_POS_X, COMBO_BALLOON_POS_Y, COMBO_BALLOON_POS_Z),
		RectWH(0, ComboBalloonHight(), COMBO_BALLOON_WIDTH, COMBO_BALLOON_MIN_HIGHT)
		);

		DX9::SpriteBatch->DrawSimple(
			combo_text.Get(),
			SimpleMath::Vector3(COMBO_TEXT_POS_X, COMBO_TEXT_POS_Y, 0.0f)
		);

		DX9::SpriteBatch->DrawSimple(
			combo_number.Get(),
			SimpleMath::Vector3(COMBO_ONE_DIGIT_POS_X, COMBO_ONE_DIGIT_POS_Y, 0.0f),
			RectWH(ComboOneDigit(), 0, COMBO_NUMBER_WIDTH, COMBO_NUMBER_HIGHT)
		);

		if (IsComboTwoDigit()) {
			DX9::SpriteBatch->DrawSimple(
				combo_number.Get(),
				SimpleMath::Vector3(COMBO_TWO_DIGIT_POS_X, COMBO_TWO_DIGIT_POS_Y, 0.0f),
				RectWH(ComboTwoDigit(), 0, COMBO_NUMBER_WIDTH, COMBO_NUMBER_HIGHT)
			);
		}

		DX9::SpriteBatch->DrawSimple(
			combo_gauge.Get(),
			SimpleMath::Vector3(COMBO_GAUGE_POS_X, COMBO_GAUGE_POS_Y, 0.0f),
			Rect(0, 0, ComboGaugeWidth(), COMBO_GAUGE_HIGHT)
		);
	}
}

void Combo::AddCombo() {
	combo++;
	AddComboTime();
	if (IsComboAnimationPlaying()) {
		ResetAnimeFrame();
	}
	combo_anime_play_flag = true;
}

void Combo::AddComboTime()
{
	float minus_combo_time = -0.6f * (combo - 1);
	combo_time = MAX_TIME + minus_combo_time;
	combo_time = std::max(combo_time, MIN_TIME);
}

void Combo::ComboTimeCount(){
	if (!combo_time_stop_flag) {
		combo_time = std::max(combo_time - time_delta, 0.0f);
	}

	if (IsComboTimeZero()) {
		ResetCombo();
	}
}

void Combo::ResetCombo() {
	combo = 0;
	combo_time = 0.0f;
}

float Combo::ComboAnimation() {
	if (combo_anime_play_flag) {
		combo_anime_frame += ANIMATION_SPEED * time_delta;
	}

	if (IsAnimationEnd()) {
		ResetAnimeFrame();
	}

	return combo_anime_frame;
}

void Combo::ResetAnimeFrame(){
	combo_anime_frame = 0.0f;
	combo_anime_play_flag = false;
}

int Combo::ComboBalloonHight() {
	return COMBO_BALLOON_MIN_HIGHT * (int)ComboAnimation();
}

int Combo::ComboOneDigit() {
	int combo_one_digit = COMBO_NUMBER_WIDTH;
	return combo_one_digit *= IsComboTwoDigit() ? combo % 10 : combo;
}

int Combo::ComboTwoDigit() {
	int combo_two_digit = COMBO_NUMBER_WIDTH;
	return combo_two_digit *= combo / 10;
}

int Combo::ComboGaugeWidth() {
	float combo_gauge_width_ = COMBO_GAUGE_DIVIDE;
	return combo_gauge_width_ * combo_time;
}