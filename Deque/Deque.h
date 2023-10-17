#pragma once
#include <iostream>

#define MAX_QUEUE_SIZE 100

//큰 배열 하나를 이용한 덱 구현
//과거에 구현해둔 덱에 At기능 추가 구현

//문제점
//MAX_QUEUE_SIZE이상의 원소가 들어가면 overflow
//빈자리 확인 및 _rear와 _front 찾는 계산 아직도 이해 못함
//

template<typename T>
class DequeWithoutChunk
{
public:
	DequeWithoutChunk() : _front(0), _rear(0), _size(0) { }

	//뒤에 삽입
	void AddRear(T target)
	{
		//큐에 빈 자리 있는지 확인 후 삽입
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

	//앞에 삽입
	void AddFront(T target)
	{
		//큐에 빈 자리 있는지 확인 후 삽입
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

	//임의 접근
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