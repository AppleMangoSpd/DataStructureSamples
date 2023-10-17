#include "MyHeap.h"

void MyHeap::Push(int added)
{
	if (_sortingType == SORTING::GREATER)
	{
		PushByMax(added);
	}
	else
	{
		PushByMin(added);
	}
}

int MyHeap::Top()
{
	return _arr[0];
}

void MyHeap::Pop()
{
	if (_size == 0)
	{
		return;
	}
	int target = _arr[1];

	_arr[1] = _arr[_size - 1];
	int parent = 1;
	int child = 0;

	while (1)
	{
		child = parent * 2;
		if (child + 1 <= _size && _arr[child] <= _arr[child + 1])
		{
			child++;
		}
		if (child > _size || _arr[child] < _arr[child + 1])
		{
			break;
		}
	}
}

void MyHeap::PushByMin(int added)
{
	int here = ++_size;

	while ((here != 1) && (added < _arr[here / 2]))
	{
		_arr[here] = _arr[here / 2];
		//부모 위치로
		here = here / 2;
	}
	_arr[here] = added;
}

void MyHeap::PushByMax(int added)
{
	int here = ++_size;

	while ((here != 1) && (added > _arr[here / 2]))
	{
		_arr[here] = _arr[here / 2];
		//부모 위치로
		here = here / 2;
	}
	_arr[here] = added;
}