#pragma once
#include "CircularLinkedList_Iterator.h"
#include <iostream>


struct node
{
	//내용물
	std::string data;
	//앞
	node* prev;
	//뒤
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
	
	//가장 앞에 삽입
	void PushFront(std::string data)
	{
		node* newNode = new node;
		newNode->data = data;
		//최초 삽입 원소일경우
		if (_head == nullptr)
		{
			//최초 삽입일 경우 원소의 머리 == 꼬리
			this->_head = newNode;
			this->_tail = newNode;
			//최초 삽입 원소의 이전노드이자 다음노드는 자기자신
			newNode->prev = newNode;
			newNode->next = newNode;
		}
		else
		{
			//전방삽입할 경우 머리의 prev는 삽입되는 노드
			_head->prev = newNode;
			//새로 생성된 노드의 next는 삽입전상태의 머리가 되고 생성된 노드 자신이 머리가 된다
			newNode->next = _head;
			this->_head = newNode;
			//원형구조를 만들기 위해 머리의 prev는 꼬리다
			newNode->prev = _tail;
		}
		_size += 1;
	}
	//가장 뒤에 삽입
	void PushBack(std::string data)
	{
		node* newNode = new node;
		newNode->data = data;
		//최초 삽입일 경우
		if (_head == nullptr)
		{
			//최초 삽입일 경우 원소의 머리 == 꼬리
			this->_head = newNode;
			this->_tail = newNode;
			//최초 삽입 원소의 이전노드이자 다음노드는 자기자신
			newNode->prev = newNode;
			newNode->next = newNode;
		}
		else
		{
			//후방삽입할 경우 꼬리의 next는 삽입되는 노드
			_tail->next = newNode;
			//새로 생성된 노드의 prev는 삽입전상태의 꼬리가 되고 생성된 노드 자신이 꼬리가 된다
			newNode->prev = this->_tail;
			this->_tail = newNode;
			//원형 구조를 만들기 위해 꼬리의 next는 머리다
			this->_tail->next = _head;
		}
		_size += 1;
	}

	const int SizeOf() const
	{
		return this->_size;
	}

	//Iterator사용을 위한 함수들. 함수 내부에서는 값 변경이 이루어지지 않는다.
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
		//입력값이 컨테이너의 크기보다 클 경우 종료
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