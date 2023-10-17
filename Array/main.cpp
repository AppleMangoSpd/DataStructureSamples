#include "MyArray.h"

int main()
{
	MyArray<int>* testArr = new MyArray<int>(6);
	testArr->Add(1);
	testArr->Add(2);
	testArr->Add(3);
	testArr->Add(4);
	testArr->Add(5);
	testArr->Add(6);

	std::cout << "testArr's capacity is " << testArr->Capacity() << std::endl;

	testArr->ViewAll();

	testArr->Delete(3);
	testArr->ViewAll();

	delete testArr;

	return 0;
}
