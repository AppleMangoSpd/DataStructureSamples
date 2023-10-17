#include "MusicPlaylist.h"
enum EEVENT
{
	ADD_MUSIC = 1, PRINT_LIST, START_PLAY, END_THIS
};

int main()
{
	MusicPlaylist* musicList = new MusicPlaylist();

	int input = 0;
	std::string musicName;

	while (input != END_THIS)
	{
		std::cout << "1. 음악 추가" << std::endl;
		std::cout << "2. 목록 출력" << std::endl;
		std::cout << "3. 재생 시작" << std::endl;
		std::cout << "4. 종료" << std::endl;
		std::cout << "명령 입력 > ";
		std::cin >> input;

		switch (input)
		{
		case ADD_MUSIC:
			std::cout << "추가할 음악 이름 : ";
			std::cin >> musicName;
			musicList->AddMusic(musicName);
			break;
		case PRINT_LIST:
			musicList->ViewAll();
			break;
		case START_PLAY:
			musicList->StartPlay();
			break;
		case END_THIS:
			musicList->End();
			break;
		case 5:
			musicList->Test();
			break;
		default:
			std::cout << "유효하지 않은 값입니다." << std::endl;
			break;
		}
	}
	delete musicList;
}

