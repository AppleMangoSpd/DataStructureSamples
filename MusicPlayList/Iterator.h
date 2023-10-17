#pragma once
#include <string>
class Iterator
{
public:
	virtual Iterator* First() = 0;
	virtual Iterator* Last() = 0;
	virtual Iterator* Next() = 0;
	virtual Iterator* Current() = 0;
	virtual std::string CurrentData() = 0;
	virtual bool IsEnd() = 0;
};