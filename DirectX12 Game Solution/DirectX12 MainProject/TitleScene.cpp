//
// MainScene.cpp
//

#include "Base/pch.h"
#include "Base/dxtk.h"
#include "SceneFactory.h"

// Initialize member variables.
TitleScene::TitleScene()
{

}

// Initialize a variable and audio resources.
void TitleScene::Initialize()
{

}

// Allocate all memory the Direct3D and Direct2D resources.
void TitleScene::LoadAssets()
{

}

// Releasing resources required for termination.
void TitleScene::Terminate()
{
	DXTK->ResetAudioEngine();
	DXTK->WaitForGpu();

	// TODO: Add your Termination logic here.

}

// Direct3D resource cleanup.
void TitleScene::OnDeviceLost()
{

}

// Restart any looped sounds here
void TitleScene::OnRestartSound()
{

}

// Updates the scene.
NextScene TitleScene::Update(const float deltaTime)
{
	// If you use 'deltaTime', remove it.
	UNREFERENCED_PARAMETER(deltaTime);

	// TODO: Add your game logic here.



	return NextScene::Continue;
}

// Draws the scene.
void MainScene::Render()
{
	// TODO: Add your rendering code here.
	DXTK->ResetCommand();
	DXTK->ClearRenderTarget(Colors::CornflowerBlue);



	DXTK->ExecuteCommandList();
}
