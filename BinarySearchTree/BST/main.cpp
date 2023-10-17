#include <iostream>
#include "BST.h"

int main()
{
	BST* Tree = new BST();
	Tree->Insert(12);
	Tree->Insert(10);
	Tree->Insert(20);
	Tree->Insert(8);
	Tree->Insert(11);
	Tree->Insert(15);
	Tree->Insert(28);
	Tree->Insert(4);
	Tree->Insert(2);

	std::cout << "���� ��ȸ(�������� ��ȸ): ";
	//BST�� ��� ���Ҹ� ������������ ����մϴ�.
	Tree->InOrder(); 
	std::cout << std::endl;

	std::cout << "�������� ��ȸ: ";
	Tree->DescendingOrder();
	std::cout << std::endl;

	Tree->DeleteValue(12);
	std::cout << "12���� �� ���� ��ȸ: ";
	Tree->InOrder();
	std::cout << std::endl;

	if (Tree->Find(12))
	{
		std::cout << "���� 12�� Ʈ���� �ֽ��ϴ�." << std::endl;
	}
	else
	{
		std::cout << "���� 12�� Ʈ���� �����ϴ�." << std::endl;
	}

	delete Tree;
}