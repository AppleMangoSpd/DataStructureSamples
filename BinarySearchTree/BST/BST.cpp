#include "BST.h"
#include <iostream>

const Node* BST::Find(const int target) const
{
	return this->Find_impl(this->_root, target);
}

void BST::Insert(const int target)
{
	//�ֻ�����尡 ������� ���
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
	//���� ��尡 ������� ���
	if (!current)
	{
		std::cout << std::endl;
		return nullptr;
	}
	//target ���� ���� ����� �����Ϳ� ��ġ�ϴ� ���
	if (current->_data == target)
	{
		std::cout << target << "��(��) ã�ҽ��ϴ�." << std::endl;
		return current;
	}
	//target ���� ���� ��� ���ʿ� �ִ� ��� (target < ���� ��� ������)
	if (target < current->_data)
	{
		std::cout << current->_data << "���� �������� �̵� : ";
		return Find_impl(current->_left, target);
	}

	//target ���� ���� ��� �����ʿ� �ִ� ��� (target > ���� ��� ������)
	std::cout << current->_data << "���� ���������� �̵� : ";
	return Find_impl(current->_right, target);
}

void BST::Insert_impl(Node* current, const int target)
{
	//���Դ���� ���� ����� ������ ���� ���
	if (target < current->_data)
	{
		//�������� ���ʳ�尡 ������� ���
		if (!current->_left)
		{
			current->_left = new Node{ target, nullptr,nullptr };
		}
		//���ʳ�� ����� ��͸� ���� �������� ���ʳ�� ����
		else
		{
			Insert_impl(current->_left, target);
		}
	}
	//���Դ���� ���� ����� ������ ũ�ų� ���� ���
	else
	{
		//�������� �����ʳ�尡 ������� ���
		if (!current->_right)
		{
			current->_right = new Node{ target, nullptr,nullptr };
		}
		//�����ʳ�� ����� ��͸� ���� �������� �����ʳ�� ����
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
	//���� ���� ��� �湮
	InOrder_impl(start->_left);
	//���� ��� ���
	std::cout << start->_data << " ";
	//������ ���� ��� �湮
	InOrder_impl(start->_right);
}

void BST::DescendingOrder_impl(const Node* start) const
{
	if (!start)
	{
		return;
	}
	//������ ���� ���
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
	//��������� ���� ��庸�� ���� ���
	if (target < start->_data)
	{
		start->_left = Delete_impl(start->_left, target);
	}
	//��������� ���� ��庸�� Ŭ ���
	else if (target > start->_data)
	{
		start->_right = Delete_impl(start->_right, target);
	}

	//��������� ���� ����� ��� 
	else
	{
		//�ڽĳ�尡 ���� ���ų�, ���� �ڽ� ��常 ���� ���
		if (!start->_left)
		{
			Node* tmp = start->_right;
			delete start;
			return tmp;
		}
		//������ �ڽ� ��常 ���� ���
		if (!start->_right)
		{
			Node* tmp = start->_left;
			delete start;
			return tmp;
		}
		//�ڽ� ��尡 �� �� �ִ� ���
		//�ļ� ��� �˻� �� �����
		Node* succNode = this->Successor(start);
		start->_data = succNode->_data;

		//������ ���� ��忡�� �ļ� ��� ã�Ƽ� ����
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