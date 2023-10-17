#include "Troops.h"
#include "NTree.h"
#include "Units.h"
#include "Items.h"

#include <iostream>

Troops::Troops() : _maxUnitVolume(3)
{
	_nTree = new NTree();

	Node* root = new Node("root");
	_nTree->insert(root, _nTree->getRoot());

	_troopSize = 1;
	_nTree->insert("Troop" + std::to_string(_troopSize), "root");
}

void Troops::addUnit(Node* added)
{
	Node* location = findEmptyTroop();

	_nTree->insert(added, location);
}

void Troops::addUnitItem(BaseItem* added) const
{
	Node* tempTargetLocation = _nTree->find(added->_owner);

	//아이템 주인이 없을경우
	if (nullptr == tempTargetLocation)
	{
		std::cout << added->_name << "의 주인인 "<< added->_owner << "이(가) 존재하지 않습니다." << std::endl;
		std::cout << added->_name << " 추가에 실패했습니다.\n" << std::endl;
		return;
	}
	//선행요건 충족 확인
	if ("none" != added->_requiredItem)
	{
		if (!_nTree->find(added->_requiredItem))
		{
			std::cout << "부대내에 " << added->_requiredItem << "이(가) 존재하지 않습니다." << std::endl;
			std::cout << added->_name << " 추가에 실패했습니다.\n" << std::endl;
			return;
		}

	}
	_nTree->insert(added, tempTargetLocation);
	std::cout << tempTargetLocation->_name <<"에게 "<< added->_name << "아이템 추가 성공\n" << std::endl;
}

void Troops::groupInfo() const
{
	std::cout << "그룹을 조회합니다." << std::endl;
	showByTroop();
	std::cout << std::endl;
}

void Troops::showByTroop() const
{
	std::vector<Node*>::const_iterator nodeIter;
	std::vector<Node*>::const_iterator childNodeIter;
	//Troop(부대) 순회
	for (nodeIter = _nTree->getRoot()->_children.begin();
		nodeIter != _nTree->getRoot()->_children.end();
		++nodeIter)
	{
		std::cout << (*nodeIter)->_name << " -> ";
		//Troop 내부 Unit 순회
		for (childNodeIter = (*nodeIter)->_children.begin();
			childNodeIter != (*nodeIter)->_children.end();
			++childNodeIter)
		{
			std::cout << (*childNodeIter)->_name;
			if (!(*childNodeIter)->_children.empty())
			{
				showWeapon(*childNodeIter);
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

void Troops::showWeapon(Node* target) const
{
	std::vector<Node*>::const_iterator nodeIter;
	for (nodeIter = target->_children.begin();
		nodeIter != target->_children.end();
		++nodeIter)
	{
		std::cout << "-"  << (*nodeIter)->_name;
	}
}

Node* Troops::findEmptyTroop()
{
	Node* tempNode = nullptr;

	std::vector<Node*>::iterator nodeIter;
	for (nodeIter = _nTree->getRoot()->_children.begin();
		nodeIter != _nTree->getRoot()->_children.end();
		++nodeIter)
	{
		if ((*nodeIter)->_children.size() < _maxUnitVolume)
		{
			tempNode = *nodeIter;
		}
	}

	if (_nTree->getRoot()->_children.back()->_children.size() 
		== _maxUnitVolume)
	{
		_troopSize += 1;
		_nTree->insert("Troop" + std::to_string(_troopSize), "root");
		tempNode = _nTree->getRoot()->_children.back();
	}
	return tempNode;
}