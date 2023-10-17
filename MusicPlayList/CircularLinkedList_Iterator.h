#pragma once
#include "Iterator.h"

class CircularLinkedList;

class CircularLinkedList_Iterator : public Iterator
{
public:
	CircularLinkedList_Iterator(CircularLinkedList* input);
	~CircularLinkedList_Iterator();
	//Iterator�������̽��� ��� ����
	Iterator* First() override;
	Iterator* Last() override;
	Iterator* Next() override;
	Iterator* Current() override;
	std::string CurrentData() override;
	bool IsEnd() override;

	void SetIndex(int _input);
	int GetIndex() const;
private:
	//�����̳��� ���° ���빰����
	int _index;

	CircularLinkedList* _circularLinkedList;
};

