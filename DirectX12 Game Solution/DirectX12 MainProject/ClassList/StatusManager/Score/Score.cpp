#include "ClassList/StatusManager/Score/Score.h"

Score::Score() {
	score_ = 0.0f;
	add_score_ = 0.0f;
	time_delta = 0.0f;
	max_score = 0.0f;
}

void Score::Initialize() {
	score_ = 0.0f;
	add_score_ = 0.0f;
	time_delta = 0.0f;
}

void Score::Update(const float deltaTime) {
	time_delta = deltaTime;
	CalcScore();
}

void Score::SetAddScore(float add_score) {
	add_score_ = add_score;
	AddMaxScore();
}

void Score::AddMaxScore() {
	max_score += add_score_; 
	max_score = std::clamp(max_score, 0.0f, 3000.0f);
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