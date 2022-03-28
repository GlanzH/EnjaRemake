#pragma once

#include "Base/pch.h"
#include "Base/dxtk.h"


using namespace DirectX;

class Score {
public:

	~Score() {};

	void Initialize();
	void Update(const float deltaTime);

	static Score& Instance() {
		static Score instance;
		return instance;
	}

	void SetAddScore(float add_score);
	float GetScore() { return score_; }

private:
	Score();

	void AddMaxScore();
	void CalcScore();
	void ScoreUp();
	void ScoreDown();
	bool IsScorePlus() { return max_score > score_; }

	float score_;
	float add_score_;
	float time_delta;
	float max_score;
	const float SCORE_UPDN_SPEED = 300.0f;
};