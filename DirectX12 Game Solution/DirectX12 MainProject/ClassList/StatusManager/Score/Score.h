#pragma once

#include "Base/pch.h"
#include "Base/dxtk.h"

using namespace DirectX;

class Score {
public:
	~Score() {};

	void Initialize();
	void LoadAseets();
	void Update(const float deltaTime);
	void Render();

	void SetAddScore(float add_score);
	float GetScore() { return score_; }

	static Score& Instance() {
		static Score instance;
		return instance;
	}
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
	const float SCORE_MAX_VALUE = 3000.0f;
	const float SCORE_UPDN_SPEED = 300.0f;
	
	//スコアゲージ
	int ScoreGaugeWidth();
	DX9::SPRITE score_gauge_top;
	DX9::SPRITE score_gauge_bottom;

	const int SCORE_MAX_HIGHT = 96;
	const int SCORE_MIN_WIDTH = 81;
	const float SCORE_GAUGE_POS_X = 30.0f;
	const float SCORE_GAUGE_POS_Y = 20.0f;
	const float SCORE_GAUGE_BTM_POS_Z = 0.0f;
	const float SCORE_GAUGE_TOP_POS_Z = -1.0f;
	const float SCORE_GAUGE_DIVIDE = 0.113f;	//スコアゲージ3000分の1の数(描画時使用)
};