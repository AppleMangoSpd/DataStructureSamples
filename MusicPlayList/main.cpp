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
		std::cout << "1. ���� �߰�" << std::endl;
		std::cout << "2. ��� ���" << std::endl;
		std::cout << "3. ��� ����" << std::endl;
		std::cout << "4. ����" << std::endl;
		std::cout << "��� �Է� > ";
		std::cin >> input;

		switch (input)
		{
		case ADD_MUSIC:
			std::cout << "�߰��� ���� �̸� : ";
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
			std::cout << "��ȿ���� ���� ���Դϴ�." << std::endl;
			break;
		}
	}
	delete musicList;
}

