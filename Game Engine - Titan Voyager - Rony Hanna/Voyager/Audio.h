#pragma once
#ifndef __AUDIO_H__
#define __AUDIO_H__

#include "Dependencies\FMOD\Include\fmod.hpp"
#include <vector>
#include <map>

class Audio
{
public:
	Audio();

	static Audio& GetInstance()
	{
		static Audio instance;
		return instance;
	}

	Audio(Audio const&) = delete;
	void operator=(Audio const&) = delete;

	bool Init();
	bool LoadAudioFile(char* file, char* nameId);

	FMOD::Channel** GetAudioChannel() { return m_p2pAudioChannel; }
	FMOD::System* GetAudioManager() { return m_pAudioManager; }
	std::map<char*, FMOD::Sound*> GetSoundsMap() { return m_sounds; }
	bool IsSoundPlaying();

private:
	~Audio();

	FMOD::Channel* m_pAudioChannel;
	FMOD::Channel** m_p2pAudioChannel = &m_pAudioChannel;

	FMOD::System* m_pAudioManager;
	std::map<char*, FMOD::Sound*> m_sounds;
};

#endif // !__AUDIO_H__