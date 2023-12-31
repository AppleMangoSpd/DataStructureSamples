#include "BloomFilter.h"

#include <iostream>
#include <regex>
#include <locale.h>
//#include <comdef.h>
#include <atlconv.h>

#include <openssl/md5.h>

void BloomFilter::hash(const std::string& key)
{
	MD5(reinterpret_cast<const unsigned char*>(key.data()), key.length(), hashValue);
}

void BloomFilter::add(const std::string& key)
{
	if (!checkIdRule(key))
	{
		std::cout << key << " => 닉네임 규칙 오류!" << std::endl;
		std::cout << std::endl;

		return;
	}
	if (mayContain(key))
	{
		return;
	}
	hash(key);
	for (auto it = &hashValue[0]; it < &hashValue[nHashes]; it++)
	{
		bits[*it % bits.size()] = true;
	}
	std::cout << "닉네임이 등록되었습니다 => " << key << std::endl;
	std::cout << std::endl;
}

bool BloomFilter::mayContain(const std::string& key)
{
	hash(key);
	for (auto it = &hashValue[0]; it < &hashValue[nHashes]; it++)
	{
		if (!bits[*it % bits.size()])
		{
			std::cout << key << " => 사용할 수 있는 닉네임입니다." << std::endl;
			return false;
		}
	}
	std::cout << key << " => 이미 사용 중입니다." << std::endl;
	std::cout << std::endl;
	return true;
}

bool BloomFilter::checkIdRule(std::string target)
{
	_wsetlocale(LC_ALL, L"korean");

	std::wstring convertToWstring(target.begin(), target.end());

	USES_CONVERSION;
	convertToWstring = std::wstring(A2W(target.c_str()));

	std::wregex rule(LR"(^[가-힣|a-z|A-Z]{4,16}$)");
	if (std::regex_match(convertToWstring, rule))
	{
		return true;
	}
	else
	{
		return false;
	}
}