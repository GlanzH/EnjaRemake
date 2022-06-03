#include "ClassList/StatusManager/Score/Score.h"

Score::Score() {
	score_	   = 0.0f;
	add_score_ = 0.0f;
	time_delta = 0.0f;
	max_score  = 0.0f;

	score_gauge_bottom = nullptr;
	score_gauge_top	   = nullptr;
}

void Score::Initialize() {
	score_	   = 0.0f;
	add_score_ = 0.0f;
	time_delta = 0.0f;
	max_score  = 0.0f;
}

void Score::LoadAseets() {
	score_gauge_bottom = DX9::Sprite::CreateFromFile(DXTK->Device9, L"UI/Score/scoreui_coin_bottom.png");
	score_gauge_top	   = DX9::Sprite::CreateFromFile(DXTK->Device9, L"UI/Score/scoreui_coin_top.png"   );
}

void Score::Update(const float deltaTime) {
	time_delta = deltaTime;
	CalcScore();
}

void Score::Render() {
	DX9::SpriteBatch->DrawSimple(
		score_gauge_bottom.Get(),
		SimpleMath::Vector3(SCORE_GAUGE_POS_X, SCORE_GAUGE_POS_Y, SCORE_GAUGE_BTM_POS_Z)
	);

	DX9::SpriteBatch->DrawSimple(
		score_gauge_top.Get(),
		SimpleMath::Vector3(SCORE_GAUGE_POS_X, SCORE_GAUGE_POS_Y, SCORE_GAUGE_TOP_POS_Z),
		RectWH(0, 0, ScoreGaugeWidth(), SCORE_MAX_HIGHT)
	);
}

void Score::SetAddScore(float add_score) {
	add_score_ = add_score;
	AddMaxScore();
}

void Score::AddMaxScore() {
	max_score += add_score_; 
	max_score = std::clamp(max_score, 0.0f, SCORE_MAX_VALUE);
}

void Score::CalcScore()
{
	if (IsScorePlus()) {
		ScoreUp();
	}
	else {
		ScoreDown();
	}
}

void Score::ScoreUp() {
	score_ = std::min(score_ + SCORE_UPDN_SPEED * time_delta, max_score);
}

void Score::ScoreDown() {
	score_ = std::max(score_ - SCORE_UPDN_SPEED * time_delta, max_score);
}

int Score::ScoreGaugeWidth()
{
	float score_gauge = score_ * SCORE_GAUGE_DIVIDE;
	return SCORE_MIN_WIDTH + (int)score_gauge;
}