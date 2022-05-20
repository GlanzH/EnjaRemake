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
	//�A�j���[�V����
	void ResetaAnimeFlag() { anime_flag = false; }	//�A�j���t���O�̃��Z�b�g
	bool GetAnimeFlag() { return anime_flag; }	//�A�j���[�V�����Đ��t���O
private:
	//�A�j���[�V����
	bool anime_flag;	//true:�A�j���[�V�����Đ� false:��~
};
	


	

	