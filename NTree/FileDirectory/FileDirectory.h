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

	//���� ���
	void ShowHowToUse();
	//�Է¹޴� �Լ�
	void InputControl();

	//���� ���丮�� ���Ե� ���丮, ���� ���
	void StartShowContents() const;
	void ShowContents() const;

	//���� ���丮 ����
	void StartChangCurrentDir();
	void ChangeCurrentDir(std::string name);

	//���丮 ����(���� ���丮�� ���� ���丮)
	void StartMakeDir();
	void MakeDir(std::string name);

	//���� ��� ���
	void StartShowRoute() const;
	void ShowRoute() const;

	//���� ���丮�� ���� ����
	void StartMakeFile();
	void MakeFile(std::string fileName);

	//����
	void Exit();
	

	//���� ���丮 ���
	Node* _currentDirNode;
	NTree* _nTree;

	bool _isEnd;
};