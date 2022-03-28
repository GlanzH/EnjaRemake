#pragma once
#include <Base/pch.h>
#include <Base/dxtk.h>

using namespace DirectX;

class UIManager {
public:
	~UIManager() {};

	void Initialize();
	void LoadAssets();
	void Update(const float deltaTime);
	void Render();

	static UIManager& Instance() {
		static UIManager instance;
		return instance;
	}

private:
	UIManager();

	float time_delta;
	//スコアゲージ
	DX9::SPRITE score_gauge_top;
	DX9::SPRITE score_gauge_bottom;

	int score_gauge_width;
	float score_gauge;

	const int SCORE_MAX_HIGHT = 96;
	const int SCORE_MIN_WIDTH = 81;
	const float SCORE_GAUGE_POS_X = 30.0f;
	const float SCORE_GAUGE_POS_Y = 20.0f;
	const float SCORE_GAUGE_BTM_POS_Z = 0.0f;
	const float SCORE_GAUGE_TOP_POS_Z = -1.0f;
	const float SCORE_GAUGE_DIVIDE = 0.113f;	//スコアゲージ3000分の1の数(描画時使用)
};