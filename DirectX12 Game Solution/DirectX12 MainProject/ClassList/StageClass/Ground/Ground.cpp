#include "Ground.h"

void Ground::LoadAseets()
{
	forest = DX9::Model::CreateFromFile(DXTK->Device9, L"Model/Theater/bg_forest.X");

	forest->SetPosition(0.0,-25.0,7.0);

}

int Ground::Update()
{
	return 0;
}

void Ground::Render()
{
}
