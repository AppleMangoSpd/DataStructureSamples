#include "MusicPlaylist.h"

MusicPlaylist::MusicPlaylist()
{
	_musicList = new CircularLinkedList();
}
MusicPlaylist::~MusicPlaylist()
{
	delete _musicList;
}

void MusicPlaylist::AddMusic(std::string musicName)
{
	_musicList->PushBack(musicName);
	std::cout << "\n";
}

void MusicPlaylist::ViewAll()
{
	Iterator* testIter = new CircularLinkedList_Iterator(_musicList);
	int num = 1;
	if (_musicList->IsEmpty())
	{
		std::cout << "목록이 비어있습니다." << std::endl;
		return;
	}

	for (Iterator* iter = _musicList->Begin(); !iter->IsEnd(); iter = iter->Next())
	{
		std::cout << num << ". ";
		std::cout << iter->CurrentData() << std::endl;
		num += 1;
	}
	std::cout << num << ". ";
	std::cout << _musicList->End()->CurrentData() << std::endl;

	std::cout << "\n";
}

void MusicPlaylist::StartPlay()
{
	Iterator* iter = _musicList->Begin();
	int input = 1;
	if (_musicList->IsEmpty())
	{
		return;
	}

	while (input > 0)
	{
		std::cout << iter->CurrentData() << std::endl;
		std::cout << "다음(1), 종료(0) > ";
		std::cin >> input;
		iter = iter->Next();
	}
	std::cout << "\n";
}

void MusicPlaylist::End()
{
	std::cout << "종료합니다." << std::endl;
}

void MusicPlaylist::Test()
{
	Iterator* testIter = new CircularLinkedList_Iterator(_musicList);
	
	std::cout << _musicList->End()->CurrentData() << std::endl;
}
