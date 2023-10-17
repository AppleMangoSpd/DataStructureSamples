#pragma once
#define MAX_SIZE 100

enum SORTING
{
	LESS,
	GREATER
};
class MyHeap
{
public:
	MyHeap() : _size(0), _sortingType(SORTING::GREATER) {}
	MyHeap(SORTING type) : _size(0), _sortingType(type) {}
	void Push(int added);
	int Top();
	void Pop();
private:
	const SORTING _sortingType;

	int _arr[MAX_SIZE];
	int _size;

	void PushByMin(int added);
	void PushByMax(int added);
};