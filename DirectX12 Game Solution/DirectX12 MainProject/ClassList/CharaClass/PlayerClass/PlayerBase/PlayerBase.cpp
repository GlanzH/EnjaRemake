#include"PlayerBase.h"

bool PlayerBase::Initialize()
{
	//プレイヤーのSE ファイル読み込み
//攻撃-SE
	attack_se = XAudio::CreateSoundEffect(DXTK->AudioEngine, L"BGM_SE\\Player\\player_attack.wav");

	//攻撃が弾かれる　SE
	frip_se = XAudio::CreateSoundEffect(DXTK->AudioEngine, L"BGM_SE\\Player\\player_play.wav");

	//ダメージ SE
	damage_se = XAudio::CreateSoundEffect(DXTK->AudioEngine, L"BGM_SE\\Player\\player_damage.wav");

	//止め SE
	stop_se = XAudio::CreateSoundEffect(DXTK->AudioEngine, L"BGM_SE\\Player\\player_stop.wav");

	return false;
}

void PlayerBase::LoadAssets()
{
}

int PlayerBase::Update()
{
	return 0;
}

void PlayerBase::Render()
{
}
	