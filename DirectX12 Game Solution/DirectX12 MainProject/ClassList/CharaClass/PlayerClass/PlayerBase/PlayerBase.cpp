#include"PlayerBase.h"

bool PlayerBase::Initialize()
{
	//�v���C���[��SE �t�@�C���ǂݍ���
//�U��-SE
	attack_se = XAudio::CreateSoundEffect(DXTK->AudioEngine, L"BGM_SE\\Player\\player_attack.wav");

	//�U�����e�����@SE
	frip_se = XAudio::CreateSoundEffect(DXTK->AudioEngine, L"BGM_SE\\Player\\player_play.wav");

	//�_���[�W SE
	damage_se = XAudio::CreateSoundEffect(DXTK->AudioEngine, L"BGM_SE\\Player\\player_damage.wav");

	//�~�� SE
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
	