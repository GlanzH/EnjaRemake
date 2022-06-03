#pragma once

#include "Base/pch.h"
#include "Base/dxtk.h"
#include "Base/DX12Effekseer.h"
#include "../../../DirectXTK12/Src/SharedResourcePool.h"

using namespace DirectX;

class ResourceManager {
public:

	EFFECT LoadEffect(LPCWSTR effect);

	static ResourceManager Instance() {
		ResourceManager instance;
		return instance;
	}



private:
	std::map<LPCWSTR, EFFECT> effect_name;

};