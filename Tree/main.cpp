#include <iostream>
#include "Tree.h"
#include "TreeTraversal.h"
int main()
{
	//생성방식 굳이 이렇게?
	Tree* tree = Tree::CreateTree("CEO");
	TreeTraversal* traversal = new TreeTraversal();

	tree->AddSubordinate("CEO", "부사장");
	tree->AddSubordinate("부사장", "IT부장");
	tree->AddSubordinate("부사장", "마케팅부장");
	tree->AddSubordinate("IT부장", "보안팀장");
	tree->AddSubordinate("IT부장", "앱개발팀장");
	tree->AddSubordinate("마케팅부장", "물류팀장");
	tree->AddSubordinate("마케팅부장", "홍보팀장");
	tree->AddSubordinate("부사장", "재무부장");
	std::cout << std::endl;

	std::cout << "전위 순회" << std::endl;
	traversal->PreOrder(tree->GetRoot());
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "중위 순회" << std::endl;
	traversal->InOrder(tree->GetRoot());
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "후위 순회" << std::endl;
	traversal->PostOrder(tree->GetRoot());
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "레벨 순서 순회" << std::endl;
	traversal->LevelOrder(tree->GetRoot());
	std::cout << std::endl;
	std::cout << std::endl;

	delete tree;
	delete traversal;
}