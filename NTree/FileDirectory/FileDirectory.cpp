#include "FileDirectory.h"
#include <iostream>
#include <stack>
#include "NTree.h"

FileDirectory::FileDirectory() :_isEnd(false)
{
	_nTree = new NTree();
	_nTree->Insert("RootDirectory", " ");
	_currentDirNode = _nTree->GetRoot();
	_isEnd = false;
}

void FileDirectory::StartFileDirectory()
{
	std::cout << "파일 디렉토리를 시작합니다." << std::endl;
	this->StartLoop();
}

void FileDirectory::StartLoop()
{
	while (!_isEnd)
	{
		this->InputControl();
	}
}

void FileDirectory::ShowHowToUse()
{
	std::cout << "명령어 목록" << std::endl;
	std::cout << "1. ls - 현재 디렉토리에 포함된 디렉토리, 파일 출력." << std::endl;
	std::cout << "2. cd - 현재 디렉토리 변경." << std::endl;
	std::cout << "3. mkdir - 디렉토리 생성." << std::endl;
	std::cout << "4. pwd - 현재 경로 출력." << std::endl;
	std::cout << "5. vi - 파일 생성." << std::endl;
	std::cout << "6. exit - 현재 디렉토리에 포함된 디렉토리, 파일 출력." << std::endl;
}

void FileDirectory::InputControl()
{
	std::cout << "> ";
	std::string input;
	std::cin >> input;
	if ("ls" == input)
	{
		this->StartShowContents();
	}
	else if ("cd" == input)
	{
		this->StartChangCurrentDir();
	}
	else if ("mkdir" == input)
	{
		this->StartMakeDir();
	}
	else if ("pwd" == input)
	{
		this->StartShowRoute();
	}
	else if ("vi" == input)
	{
		this->StartMakeFile();
	}
	else if ("exit" == input)
	{
		this->Exit();
	}
	else if ("help" == input)
	{
		this->ShowHowToUse();
	}
	else
	{
		std::cout << "유효하지 않은 입력값입니다." << std::endl;
	}
	std::cout << "\n";
}

void FileDirectory::StartShowContents() const
{
	this->ShowContents();
}

void FileDirectory::ShowContents() const
{
	std::vector<Node*>::iterator nodeIter;
	std::vector<std::string>::iterator strIter;
	//디렉토리 출력
	for (nodeIter = _currentDirNode->_children.begin();
		nodeIter != _currentDirNode->_children.end();
		++nodeIter)
	{
		std::cout << "d " << (*nodeIter)->_name << std::endl;
	}
	//파일출력
	for (strIter = _currentDirNode->_data.begin();
		strIter != _currentDirNode->_data.end();
		++strIter)
	{
		std::cout << "- " << (*strIter) << std::endl;
	}

}

void FileDirectory::StartChangCurrentDir()
{
	std::string input;

	std::cout << "변경 디렉토리 이름 > ";
	std::cin >> input;
	//상위 디렉토리로 이동
	if (".." == input)
	{
		if (nullptr != _currentDirNode->_parent)
		{
			this->ChangeCurrentDir(_currentDirNode->_parent->_name);
		}
		else
		{
			std::cout << "최상위 다렉토리입니다." << std::endl;
		}
	}
	else
	{
		this->ChangeCurrentDir(input);
	}
}

void FileDirectory::ChangeCurrentDir(std::string name)
{
	Node* _tempNode = _nTree->Find(name);
	if (nullptr == _tempNode)
	{
		std::cout << "FileDirectory오류!: " << name << " 값이 존재하지 않습니다." << std::endl;
	}
	else
	{
		_currentDirNode = _tempNode;
	}
}

void FileDirectory::StartMakeDir()
{
	std::string input;
	 
	std::cout << "생성 디렉토리 이름 > ";
	std::cin >> input;

	this->MakeDir(input);
}

void FileDirectory::MakeDir(std::string name)
{
	_nTree->Insert(name, _currentDirNode->_name);
}

void FileDirectory::StartShowRoute() const
{
	this->ShowRoute();
}

void FileDirectory::ShowRoute() const
{
	std::stack<Node*> nodeContainer;

	Node* tempNode = _currentDirNode;

	while (nullptr != tempNode)
	{
		nodeContainer.push(tempNode);
		tempNode = tempNode->_parent;
	}
	
	while (!nodeContainer.empty())
	{
		std::cout << nodeContainer.top()->_name << "/";
		nodeContainer.pop();
	}
}

void FileDirectory::StartMakeFile()
{
	std::string input;

	std::cout << "생성 파일 이름 > ";
	std::cin >> input;

	this->MakeFile(input);
}

void FileDirectory::MakeFile(std::string fileName)
{
	_nTree->AddData(fileName, _currentDirNode->_name);
}

void FileDirectory::Exit()
{
	std::cout << "FileDirectory를 종료합니다." << std::endl;
	this->_isEnd = true;
	delete _nTree;
	delete _currentDirNode;
}