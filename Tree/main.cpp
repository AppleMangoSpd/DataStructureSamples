#include <iostream>
#include "Tree.h"
#include "TreeTraversal.h"
int main()
{
	//������� ���� �̷���?
	Tree* tree = Tree::CreateTree("CEO");
	TreeTraversal* traversal = new TreeTraversal();

	tree->AddSubordinate("CEO", "�λ���");
	tree->AddSubordinate("�λ���", "IT����");
	tree->AddSubordinate("�λ���", "�����ú���");
	tree->AddSubordinate("IT����", "��������");
	tree->AddSubordinate("IT����", "�۰�������");
	tree->AddSubordinate("�����ú���", "��������");
	tree->AddSubordinate("�����ú���", "ȫ������");
	tree->AddSubordinate("�λ���", "�繫����");
	std::cout << std::endl;

	std::cout << "���� ��ȸ" << std::endl;
	traversal->PreOrder(tree->GetRoot());
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "���� ��ȸ" << std::endl;
	traversal->InOrder(tree->GetRoot());
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "���� ��ȸ" << std::endl;
	traversal->PostOrder(tree->GetRoot());
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "���� ���� ��ȸ" << std::endl;
	traversal->LevelOrder(tree->GetRoot());
	std::cout << std::endl;
	std::cout << std::endl;

	delete tree;
	delete traversal;
}