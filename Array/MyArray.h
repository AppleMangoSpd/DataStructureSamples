#pragma once
#include <iostream>

template<typename T>

class MyArray
{
public:
	MyArray() 
	{
		std::cout << "Please set size of array" << std::endl;
		int n;
		std::cin >> n;

		_array = new T[n];
		_arraySize = n;
		_currentSize = 0;
	};
	MyArray(const int n) 
	{
		_array = new T[n];
		_arraySize = n;
		_currentSize = 0;
	};
	~MyArray() 
	{
		if (_array)
		{
			//delete[]_array;
		}
	};

	void Add(const T target) 
	{
		if (_currentSize == _arraySize)
		{
			std::cout << "Array is full" << std::endl;
			return;
		}
		else
		{
			_array[_currentSize] = target;
			_currentSize += 1;
		}
	};
	/*void Delete(const T target) 
	{
		int targetIndex = Search(target);
		_array[targetIndex] = 0;
		for (int i = targetIndex; i < _currentSize; i++)
		{
			_array[i] = _array[i + 1];
		}
		_array[_currentSize] = 0;
		_currentSize -= 1;
	};*/
	void Delete(const int target)
	{
		int targetIndex = target - 1;
		if (targetIndex > _currentSize)
		{
			std::cout << "Out of index" << std::endl;
			return;
		}
		for (int i = targetIndex; i < _currentSize; i++)
		{
			_array[i] = _array[i + 1];
		}
		_array[_currentSize] = 0;
		_currentSize -= 1;
	}
	T At(const int index)
	{ 
		if (index > _arraySize)
		{
			std::cout << "Out of index" << std::endl;
			return nullptr;
		}
		else
		{
			return _array[index];
		}
	};

	//int Search(const T target)
	//{
	//	bool isFound = false;
	//	int count = 0;
	//	int result = 0;
	//	while (!isFound || (count <= _currentSize))
	//	{
	//		if (_array[count] == target)
	//		{
	//			isFound = true;
	//			result = count;
	//		}
	//		count += 1;
	//	}
	//	if (!isFound)
	//	{
	//		std::cout << "Can not found " << target << std::endl;
	//		return result;
	//	}
	//
	//	return result;
	//}

	void ViewAll()
	{
		for (int i = 0; i < _currentSize; i++)
		{
			std::cout << _array[i] << " ";
		}
		std::cout << std::endl;
	}

	int SizeOf()
	{
		return _currentSize;
	}
	int Capacity()
	{
		return _arraySize;
	}
private:
	T* _array;
	int _currentSize;
	int _arraySize;
};