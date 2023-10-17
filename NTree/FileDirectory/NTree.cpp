#include "NTree.h"
#include <iostream>
void NTree::Insert(std::string name, std::string parentName)
{
	if (nullptr == _root)
	{
		Node* childNode = new Node();
		childNode->_name = name;
		childNode->_parent = nullptr;
		_root = childNode;

		return;
	}

	Node* parentNode = Find(parentName);
	if (nullptr == parentNode)
	{
		return;
	}
	Node* childNode = new Node();
	childNode->_name = name;
	childNode->_parent = parentNode;

	parentNode->_children.push_back(childNode);
}

Node* NTree::Find(std::string name) const
{
	Node* tempNode = StartFind(_root, name);
	if (nullptr == tempNode)
	{
		std::cout << "NTree오류!: " << name << " 값이 존재하지 않습니다." << std::endl;
	}
	return tempNode;
}

void NTree::AddData(std::string data, std::string target)
{
	Node* parentNode = Find(target);
	if (nullptr == parentNode)
	{
		return;
	}
	parentNode->_data.push_back(data);
}

Node* NTree::GetRoot() const
{
	return _root;
}

Node* NTree::StartFind(Node* current, std::string target) const
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
			tempNode = StartFind(*iter, target);
			if (nullptr != tempNode)
			{
				return tempNode;
			}
		}
	}
	
	return tempNode;
}