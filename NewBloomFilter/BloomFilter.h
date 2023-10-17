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
			throw("�ؽ� �Լ� ������ �ʹ� �����ϴ�.");
		}
		if (size > 255)
		{
			throw("��� ���� ũ�Ⱑ 255���� Ŭ �� �����ϴ�.");
		}
	}
	void hash(const std::string& key);

	void add(const std::string& key);

	bool mayContain(const std::string& key);

	bool checkIdRule(std::string target);
};
