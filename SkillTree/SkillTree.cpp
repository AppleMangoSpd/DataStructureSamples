#include "SkillTree.h"
#include <iostream>
NTree::NTree()
{
	_root = new SkillNode();
	_root->_name = "Root";
	_root->_cost = 0;
}

SkillNode* NTree::Find(const std::string name) const
{
	SkillNode* tempNode = StartFind(_root, name);
	if (nullptr == tempNode)
	{
		std::cout << "NTree오류!: " << name << " 값이 존재하지 않습니다." << std::endl;
	}
	return tempNode;
}

SkillNode* NTree::StartFind(SkillNode* current, const std::string target) const
{
	SkillNode* tempNode = nullptr;
	if (target == current->_name)
	{
		return current;
	}
	else
	{
		std::vector<SkillNode*>::iterator iter;
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

void NTree::Insert(const std::string name, const std::string parentName)
{
	SkillNode* parentNode = Find(parentName);
	SkillNode* childNode;
	if (nullptr == parentNode)
	{
		return;
	}

	if(IsExist(name))
	{ 
		childNode = Find(name);
	}
	else
	{
		childNode = new SkillNode();
		childNode->_name = name;
	}
	parentNode->_children.push_back(childNode);
}

const bool NTree::IsExist(const std::string name) const
{
	if (nullptr != Find(name))
	{
		return true;
	}
	return false;
}

SkillNode* NTree::GetRoot() const
{
	return nullptr;
}

void NTree::InOrder() const
{
	StartInOrder(_root);
}

void NTree::StartInOrder(const SkillNode* start) const
{
	if (!start)
	{
		return;
	}
	
}
