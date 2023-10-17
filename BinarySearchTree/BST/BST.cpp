#include "BST.h"
#include <iostream>

const Node* BST::Find(const int target) const
{
	return this->Find_impl(this->_root, target);
}

void BST::Insert(const int target)
{
	//최상위노드가 비어있을 경우
	if (!_root)
	{
		_root = new Node{ target, nullptr, nullptr };
	}
	else
	{
		this->Insert_impl(this->_root, target);
	}
}

void BST::InOrder() const
{
	this->InOrder_impl(this->_root);
}

void BST::DescendingOrder() const
{
	this->DescendingOrder_impl(this->_root);
}

void BST::DeleteValue(const int target)
{
	_root = Delete_impl(_root, target);
}

const Node* BST::Find_impl(const Node* current, const int target) const
{
	//현재 노드가 비어있을 경우
	if (!current)
	{
		std::cout << std::endl;
		return nullptr;
	}
	//target 값이 현재 노드의 데이터와 일치하는 경우
	if (current->_data == target)
	{
		std::cout << target << "을(를) 찾았습니다." << std::endl;
		return current;
	}
	//target 값이 현재 노드 왼쪽에 있는 경우 (target < 현재 노드 데이터)
	if (target < current->_data)
	{
		std::cout << current->_data << "에서 왼쪽으로 이동 : ";
		return Find_impl(current->_left, target);
	}

	//target 값이 현재 노드 오른쪽에 있는 경우 (target > 현재 노드 데이터)
	std::cout << current->_data << "에서 오른쪽으로 이동 : ";
	return Find_impl(current->_right, target);
}

void BST::Insert_impl(Node* current, const int target)
{
	//삽입대상이 현재 노드의 값보다 작을 경우
	if (target < current->_data)
	{
		//현재노드의 왼쪽노드가 비어있을 경우
		if (!current->_left)
		{
			current->_left = new Node{ target, nullptr,nullptr };
		}
		//왼쪽노드 존재시 재귀를 통해 현재노드의 왼쪽노드 입장
		else
		{
			Insert_impl(current->_left, target);
		}
	}
	//삽입대상이 현재 노드의 값보다 크거나 같을 경우
	else
	{
		//현재노드의 오른쪽노드가 비어있을 경우
		if (!current->_right)
		{
			current->_right = new Node{ target, nullptr,nullptr };
		}
		//오른쪽노드 존재시 재귀를 통해 현재노드의 오른쪽노드 입장
		else
		{
			Insert_impl(current->_right, target);
		}
	}
}

void BST::InOrder_impl(const Node* start) const
{
	if (!start)
	{
		return;
	}
	//왼쪽 하위 노드 방문
	InOrder_impl(start->_left);
	//현재 노드 출력
	std::cout << start->_data << " ";
	//오른쪽 하위 노드 방문
	InOrder_impl(start->_right);
}

void BST::DescendingOrder_impl(const Node* start) const
{
	if (!start)
	{
		return;
	}
	//오른쪽 하위 노드
	DescendingOrder_impl(start->_right);
	std::cout << start->_data << " ";
	DescendingOrder_impl(start->_left);

}

Node* BST::Delete_impl(Node* start, const int target)
{
	if (!start)
	{
		return nullptr;
	}
	//삭제대상이 현재 노드보다 작을 경우
	if (target < start->_data)
	{
		start->_left = Delete_impl(start->_left, target);
	}
	//삭제대상이 현재 노드보다 클 경우
	else if (target > start->_data)
	{
		start->_right = Delete_impl(start->_right, target);
	}

	//삭제대상이 현재 노드일 경우 
	else
	{
		//자식노드가 전혀 없거나, 왼쪽 자식 노드만 없는 경우
		if (!start->_left)
		{
			Node* tmp = start->_right;
			delete start;
			return tmp;
		}
		//오른쪽 자식 노드만 없는 경우
		if (!start->_right)
		{
			Node* tmp = start->_left;
			delete start;
			return tmp;
		}
		//자식 노드가 둘 다 있는 경우
		//후속 노드 검색 후 덮어쓰기
		Node* succNode = this->Successor(start);
		start->_data = succNode->_data;

		//오른쪽 하위 노드에서 후속 노드 찾아서 삭제
		start->_right = Delete_impl(start->_right, succNode->_data);
	}
	return start;
}

Node* BST::Successor(Node* start) const
{
	Node* current = start->_right;
	while (current && current->_left)
	{
		current = current->_left;
	}
	return current;
}