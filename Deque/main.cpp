#pragma once
#include "Deque.h"
int main()
{
	DequeWithoutChunk<int>* test = new DequeWithoutChunk<int>();
	test->AddFront(1);
	test->AddRear(2);
	test->AddRear(3);

	std::cout << test->At(2) << std::endl;
	return 0;
}