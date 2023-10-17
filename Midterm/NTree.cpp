#include "NTree.h"

#include <iostream>

#include "Node.h"
void NTree::insert(const std::string name, const std::string parentName)
{
	if (nullptr == _root)
	{
		Node* childNode = new Node(name);
		_root = childNode;

		return;
	}

	Node* parentNode = find(parentName);
	if (nullptr == parentNode)
	{
		return;
	}
	Node* childNode = new Node(name);

	parentNode->_children.push_back(childNode);
}

void NTree::insert(Node* target, Node* parent)
{
	if (nullptr == _root)
	{
		_root = target;

		return;
	}
	parent->_children.push_back(target);
}

Node* NTree::find(std::string name) const
{
	Node* tempNode = startFind(_root, name);
	if (nullptr == tempNode)
	{
		std::cout << "NTree오류!: " << name << " 값이 존재하지 않습니다." << std::endl;
	}
	return tempNode;
}

Node* NTree::getRoot() const
{
	return _root;
}

Node* NTree::startFind(Node* current, std::string target) const
{
	Node* tempNode = nullptr;
	if (current->_name == target)
	{
		return current;
	}
	else
	{
		std::vector<Node*>::iterator iter;
		for (iter = current->_children.begin(); iter != current->_children.end(); ++iter)
		{
			tempNode = startFind(*iter, target);
			if (nullptr != tempNode)
			{
				return tempNode;
			}
		}
	}

	return tempNode;
}