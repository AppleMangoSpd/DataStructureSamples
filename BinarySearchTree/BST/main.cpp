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

	std::cout << "중위 순회(오름차순 조회): ";
	//BST의 모든 원소를 오름차순으로 출력합니다.
	Tree->InOrder(); 
	std::cout << std::endl;

	std::cout << "내림차순 조회: ";
	Tree->DescendingOrder();
	std::cout << std::endl;

	Tree->DeleteValue(12);
	std::cout << "12삭제 후 중위 순회: ";
	Tree->InOrder();
	std::cout << std::endl;

	if (Tree->Find(12))
	{
		std::cout << "원소 12는 트리에 있습니다." << std::endl;
	}
	else
	{
		std::cout << "원소 12는 트리에 없습니다." << std::endl;
	}

	delete Tree;
}