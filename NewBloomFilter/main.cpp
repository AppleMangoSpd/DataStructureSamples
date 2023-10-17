#include "BloomFilter.h"

int main()
{
	BloomFilter* bloom = new BloomFilter(128, 5);

	bloom->add("myNIck");
	bloom->add("myLongLongLongLongLongNick");
	bloom->add("한글닉네임");
	bloom->add("여덞글자이상한글닉네임");
	bloom->add("어어어어어어어어어어엄청긴한글닉네임");
	bloom->add("한글andLongLongLongLongEng");
	bloom->add("한글andEng");
	bloom->add("myNick");
	bloom->add("한글닉네임");
	bloom->add("한글andEng");

	bloom->add("한글233");

	delete bloom;
}