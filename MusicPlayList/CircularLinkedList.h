#pragma once
#include "CircularLinkedList_Iterator.h"
#include <iostream>


struct node
{
	//���빰
	std::string data;
	//��
	node* prev;
	//��
	node* next;
};

class CircularLinkedList
{
public:
	CircularLinkedList() 
	{
		_iter = new CircularLinkedList_Iterator(this);
		_size = 0;
	}
	~CircularLinkedList() { delete _iter; }
	
	//���� �տ� ����
	void PushFront(std::string data)
	{
		node* newNode = new node;
		newNode->data = data;
		//���� ���� �����ϰ��
		if (_head == nullptr)
		{
			//���� ������ ��� ������ �Ӹ� == ����
			this->_head = newNode;
			this->_tail = newNode;
			//���� ���� ������ ����������� �������� �ڱ��ڽ�
			newNode->prev = newNode;
			newNode->next = newNode;
		}
		else
		{
			//��������� ��� �Ӹ��� prev�� ���ԵǴ� ���
			_head->prev = newNode;
			//���� ������ ����� next�� ������������ �Ӹ��� �ǰ� ������ ��� �ڽ��� �Ӹ��� �ȴ�
			newNode->next = _head;
			this->_head = newNode;
			//���������� ����� ���� �Ӹ��� prev�� ������
			newNode->prev = _tail;
		}
		_size += 1;
	}
	//���� �ڿ� ����
	void PushBack(std::string data)
	{
		node* newNode = new node;
		newNode->data = data;
		//���� ������ ���
		if (_head == nullptr)
		{
			//���� ������ ��� ������ �Ӹ� == ����
			this->_head = newNode;
			this->_tail = newNode;
			//���� ���� ������ ����������� �������� �ڱ��ڽ�
			newNode->prev = newNode;
			newNode->next = newNode;
		}
		else
		{
			//�Ĺ������ ��� ������ next�� ���ԵǴ� ���
			_tail->next = newNode;
			//���� ������ ����� prev�� ������������ ������ �ǰ� ������ ��� �ڽ��� ������ �ȴ�
			newNode->prev = this->_tail;
			this->_tail = newNode;
			//���� ������ ����� ���� ������ next�� �Ӹ���
			this->_tail->next = _head;
		}
		_size += 1;
	}

	const int SizeOf() const
	{
		return this->_size;
	}

	//Iterator����� ���� �Լ���. �Լ� ���ο����� �� ������ �̷������ �ʴ´�.
	Iterator* Begin() const
	{
		return _iter->First();
	}
	Iterator* End() const
	{
		return _iter->Last();
	}
	Iterator* GetIterator() const
	{
		return _iter;
	}

	std::string At(const int input) const
	{
		//�Է°��� �����̳��� ũ�⺸�� Ŭ ��� ����
		if (this->SizeOf() < input)
		{
			return "Warning! Out of index";
		}
		int index = 1;

		node* resultNode;
		resultNode = this->_head;
		while (index < input)
		{
			resultNode = resultNode->next;
			index += 1;
		}
		return resultNode->data;
	}

	bool IsEmpty() const
	{
		if (_head == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	int _size;
	node* _head;
	node* _tail;

	Iterator* _iter;
};