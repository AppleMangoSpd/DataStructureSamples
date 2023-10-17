#pragma once
#include <string>
class NTree;
struct Node;

class FileDirectory
{
public:
	FileDirectory();

	void StartFileDirectory();
private:
	void StartLoop();

	//사용법 출력
	void ShowHowToUse();
	//입력받는 함수
	void InputControl();

	//현재 디렉토리에 포함된 디렉토리, 파일 출력
	void StartShowContents() const;
	void ShowContents() const;

	//현재 디렉토리 변경
	void StartChangCurrentDir();
	void ChangeCurrentDir(std::string name);

	//디렉토리 생성(현재 디렉토리의 하위 디렉토리)
	void StartMakeDir();
	void MakeDir(std::string name);

	//현재 경로 출력
	void StartShowRoute() const;
	void ShowRoute() const;

	//현재 디렉토리에 파일 생성
	void StartMakeFile();
	void MakeFile(std::string fileName);

	//종료
	void Exit();
	

	//현재 디렉토리 노드
	Node* _currentDirNode;
	NTree* _nTree;

	bool _isEnd;
};