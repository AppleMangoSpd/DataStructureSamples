#pragma once
#include <vector>
#include <string>

class BloomFilter
{
private:
	int nHashes;
	std::vector<bool> bits;

	static constexpr int hashSize = 128 / 8;

	unsigned char hashValue[hashSize];

public:
	BloomFilter(int size, int hashes) : bits(size), nHashes(hashes)
	{
		if (nHashes > hashSize)
		{
			throw("해시 함수 개수가 너무 많습니다.");
		}
		if (size > 255)
		{
			throw("블룸 필터 크기가 255보다 클 수 없습니다.");
		}
	}
	void hash(const std::string& key);

	void add(const std::string& key);

	bool mayContain(const std::string& key);

	bool checkIdRule(std::string target);
};
