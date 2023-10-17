//#include <iostream>
//#include <queue>
//#include <vector>
//#include "MyHeap.h"
//
//struct median
//{
//	std::priority_queue<int> maxHeap;
//	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
//
//	void push(int data)
//	{
//		if (maxHeap.size() == 0)
//		{
//			maxHeap.push(data);
//			return;
//		}
//		if (maxHeap.size() == minHeap.size())
//		{
//			if (data <= get())
//			{
//				maxHeap.push(data);
//			}
//			else
//			{
//				minHeap.push(data);
//			}
//			return;
//		}
//		if (data < get())
//		{
//			minHeap.push(maxHeap.top());
//			maxHeap.pop();
//			maxHeap.push(data);
//		}
//		else
//		{
//			minHeap.push(data);
//		}
//	}
//
//	double get()
//	{
//		if (maxHeap.size() == minHeap.size())
//		{
//			return (maxHeap.top() + minHeap.top()) / 2.0;
//		}
//		if (maxHeap.size() < minHeap.size())
//		{
//			return minHeap.top();
//		}
//		return maxHeap.top();
//	}
//};
//
//
//int main()
//{
//	median med;
//	
//
//	//MyHeap myheap;
//	//myheap.Push(3);
//	//myheap.Push(5);
//	//myheap.Push(7);
//	//myheap.Push(1);
//	//myheap.Push(9);
//
//	MyHeapByArr mha;
//	mha.Push(3);
//	mha.Push(5);
//	mha.Push(7);
//	mha.Push(1);
//	mha.Push(9);
//
//	med.insert(1);
//	std::cout << "1 »ðÀÔ ÈÄ Áß¾Ó°ª : " << med.get() << std::endl;
//
//	med.insert(5);
//	std::cout << "5 »ðÀÔ ÈÄ Áß¾Ó°ª : " << med.get() << std::endl;
//
//	med.insert(2);
//	std::cout << "2 »ðÀÔ ÈÄ Áß¾Ó°ª : " << med.get() << std::endl;
//
//	med.insert(10);
//	std::cout << "10 »ðÀÔ ÈÄ Áß¾Ó°ª : " << med.get() << std::endl;
//
//	med.insert(40);
//	std::cout << "40 »ðÀÔ ÈÄ Áß¾Ó°ª : " << med.get() << std::endl;
//}

#include <iostream>
#include <regex>

int main(void)
{
    std::regex reg("[°¡-ÆR]+");
    std::string str = "´Ù";

    if (std::regex_match(str, reg))
    {
        std::cout << str << std::endl;
    }

    return 0;
}