#include "ClassList/UI/UIManager/UIManager.h"
#include "ClassList/StatusManager/Score/Score.h"
#include "ClassList/UI/Audience/Audience.h"
#include"ClassList/StatusManager/Combo/Combo.h"

void UIManager::Initialize() {
	Score::Instance().Initialize();
	Combo::Instance().Initialize();
	Audience::Instance().Intialize();
}

void UIManager::LoadAssets() {
	Audience::Instance().LoadAseets();
	Score::Instance().LoadAseets();
	Combo::Instance().LoadAssets();
}

void UIManager::Update(const float deltaTime){
	Score::Instance().Update(deltaTime);
	Combo::Instance().Update(deltaTime);
	Audience::Instance().Update(deltaTime);
}

void UIManager::Render(){
	Audience::Instance().Render();
	Score::Instance().Render();
	Combo::Instance().Render();
}