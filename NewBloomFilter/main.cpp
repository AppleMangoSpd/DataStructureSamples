#include "BloomFilter.h"

int main()
{
	BloomFilter* bloom = new BloomFilter(128, 5);

	bloom->add("myNIck");
	bloom->add("myLongLongLongLongLongNick");
	bloom->add("�ѱ۴г���");
	bloom->add("���������̻��ѱ۴г���");
	bloom->add("������������û���ѱ۴г���");
	bloom->add("�ѱ�andLongLongLongLongEng");
	bloom->add("�ѱ�andEng");
	bloom->add("myNick");
	bloom->add("�ѱ۴г���");
	bloom->add("�ѱ�andEng");

	bloom->add("�ѱ�233");

	delete bloom;
}