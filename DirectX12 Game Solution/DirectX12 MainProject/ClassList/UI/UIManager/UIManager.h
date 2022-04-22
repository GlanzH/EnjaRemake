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
	UIManager(){};
};