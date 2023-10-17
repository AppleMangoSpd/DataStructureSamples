#include "Tree.h"
#include "Node.h"
//트리생성
Tree* Tree::CreateTree(const std::string& position)
{
	Tree* tree = new Tree();
	tree->_root = new Node(position, nullptr, nullptr);
	
	return tree;
}

Node* Tree::Find(Node* root, const std::string& target)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (root->_position == target)
	{
		return root;
	}

	Node* firstFound = this->Find(root->_first, target);
	if (firstFound != nullptr)
	{
		return firstFound;
	}
	return this->Find(root->_second, target);
}

bool Tree::AddSubordinate(const std::string& parent, const std::string& child)
{
	Node* parentNode = this->Find(_root, parent);

	if (!parentNode)
	{
		std::cout << parent << "을(를) 찾을 수 없습니다: " << std::endl;
		return false;
	}
	if(parentNode->_first && parentNode->_second)
	{
		std::cout << parent << " 아래에 " << child << "를 추가할 수 없습니다." << std::endl;
		return false;
	}
	if (!parentNode->_first)
	{
		parentNode->_first = new Node(child, nullptr, nullptr);
	}
	else
	{
		parentNode->_second = new Node(child, nullptr, nullptr);
	}
	std::cout << parent << " 아래에 " << child << "를 추가했습니다." << std::endl;

	return true;
}

const Node* Tree::GetRoot() const
{
	return this->_root;
}

void Tree::SetRoot(Node* target)
{
	this->_root = target;
}
