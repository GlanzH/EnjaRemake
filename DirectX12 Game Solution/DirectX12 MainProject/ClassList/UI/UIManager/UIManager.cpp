#include "ClassList/UI/UIManager/UIManager.h"
#include "ClassList/StatusManager/Score/Score.h"

UIManager::UIManager() {
	score_gauge_bottom = nullptr;
	score_gauge_top = nullptr;
	score_gauge_width = 0;
	score_gauge = 0;
}

void UIManager::Initialize() {
	score_gauge_width = 0;
	score_gauge = 0;
}

void UIManager::LoadAssets() {
	score_gauge_bottom = DX9::Sprite::CreateFromFile(DXTK->Device9, L"UI/Score/scoreui_coin_bottom.png");
	score_gauge_top = DX9::Sprite::CreateFromFile(DXTK->Device9, L"UI/Score/scoreui_coin_top.png");
}

void UIManager::Update(const float deltaTime){
	score_gauge = Score::Instance().GetScore() * SCORE_GAUGE_DIVIDE;
	score_gauge_width = SCORE_MIN_WIDTH + (int)score_gauge;
}

void UIManager::Render(){
	DX9::SpriteBatch->DrawSimple(
		score_gauge_bottom.Get(),
		SimpleMath::Vector3(SCORE_GAUGE_POS_X, SCORE_GAUGE_POS_Y, SCORE_GAUGE_BTM_POS_Z)
	);
	
	DX9::SpriteBatch->DrawSimple(
		score_gauge_top.Get(),
		SimpleMath::Vector3(SCORE_GAUGE_POS_X, SCORE_GAUGE_POS_Y, SCORE_GAUGE_TOP_POS_Z),
		RectWH(0, 0, score_gauge_width, SCORE_MAX_HIGHT)
	);
}