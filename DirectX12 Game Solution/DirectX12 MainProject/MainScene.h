//
// MainScene.h
//

#pragma once

#include "Scene.h"
#include"ClassList/3D/Camera/C_Camera.h"
#include"ClassList/StageClass/Ground/Ground.h"
#include"ClassList/UI/UIManager/UIManager.h"
#include"ClassList/StatusManager/Score/Score.h"

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class MainScene final : public Scene {
public:
	MainScene();
	virtual ~MainScene() { Terminate(); }

	MainScene(MainScene&&) = default;
	MainScene& operator= (MainScene&&) = default;

	MainScene(MainScene const&) = delete;
	MainScene& operator= (MainScene const&) = delete;

	// These are the functions you will implement.
	void Initialize() override;
	void LoadAssets() override;

	void Terminate() override;

	void OnDeviceLost() override;
	void OnRestartSound() override;

	NextScene Update(const float deltaTime) override;
	void Render() override;

private:
	C_Camera camera;
	Ground ground;
	D3DLIGHT9 light{};

	DX12::DESCRIPTORHEAP descriptorHeap;
	DX12::SPRITEBATCH    spriteBatch;
	DX12::HGPUDESCRIPTOR dx9GpuDescriptor;
};