#pragma once
#include <string>
#include "CircularLinkedList.h"

class MusicPlaylist
{
public:
	MusicPlaylist();
	~MusicPlaylist();
	void AddMusic(std::string musicName);
	void ViewAll();
	void StartPlay();
	void End();


	void Test();
private:
	CircularLinkedList* _musicList;
};
