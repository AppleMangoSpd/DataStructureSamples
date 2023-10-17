#pragma once
#include <iostream>

#define MAX_QUEUE_SIZE 100

//ū �迭 �ϳ��� �̿��� �� ����
//���ſ� �����ص� ���� At��� �߰� ����

//������
//MAX_QUEUE_SIZE�̻��� ���Ұ� ���� overflow
//���ڸ� Ȯ�� �� _rear�� _front ã�� ��� ������ ���� ����
//

template<typename T>
class DequeWithoutChunk
{
public:
	DequeWithoutChunk() : _front(0), _rear(0), _size(0) { }

	//�ڿ� ����
	void AddRear(T target)
	{
		//ť�� �� �ڸ� �ִ��� Ȯ�� �� ����
		if (_front != (_rear + 1) % MAX_QUEUE_SIZE)
		{
			_rear = (_rear + 1) % MAX_QUEUE_SIZE;
			_data[_rear] = target;
			_size = _size + 1;
		}
		else
		{
			std::cout << "Queue is full" << std::endl;
		}
	}

	//�տ� ����
	void AddFront(T target)
	{
		//ť�� �� �ڸ� �ִ��� Ȯ�� �� ����
		if (_front != (_rear + 1) % MAX_QUEUE_SIZE)
		{
			_data[_front] = target;
			_front = (_front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			_size = _size + 1;
		}
		else
		{
			std::cout << "Queue is full" << std::endl;
		}
	}

	//���� ����
	T At(int index)
	{
		if (index >= _size)
		{
			std::cout << "Out of index" << std::endl;
			return NULL;
		}

		int targetIndex = _front + index + 1;
		if (targetIndex >= MAX_QUEUE_SIZE)
		{
			targetIndex = targetIndex - MAX_QUEUE_SIZE;
		}
		return _data[targetIndex];
	}


private:
	T _data[MAX_QUEUE_SIZE];
	int _front; 
	int _rear;
	int _size;
};