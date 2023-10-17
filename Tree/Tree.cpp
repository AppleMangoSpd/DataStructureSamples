#include "Tree.h"
#include "Node.h"
//Ʈ������
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
		std::cout << parent << "��(��) ã�� �� �����ϴ�: " << std::endl;
		return false;
	}
	if(parentNode->_first && parentNode->_second)
	{
		std::cout << parent << " �Ʒ��� " << child << "�� �߰��� �� �����ϴ�." << std::endl;
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
	std::cout << parent << " �Ʒ��� " << child << "�� �߰��߽��ϴ�." << std::endl;

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
