#pragma once
#include"Base/pch.h"

class StatusManager
{
public:
	StatusManager();
	~StatusManager();
	void Initialize();
	void Update(const float deltaTime, int remain_enemy);
	static StatusManager& Instance() {
		static StatusManager instance;
		return instance;
	}
	//アニメーション
	void ResetaAnimeFlag() { anime_flag = false; }	//アニメフラグのリセット
	bool GetAnimeFlag() { return anime_flag; }	//アニメーション再生フラグ
private:
	//アニメーション
	bool anime_flag;	//true:アニメーション再生 false:停止
};
	


	

	