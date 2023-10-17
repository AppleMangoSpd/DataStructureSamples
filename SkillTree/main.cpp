#include "SkillTree.h"

int main()
{
	//NTree Test
	NTree* testTree = new NTree();
	testTree->Insert("1", "Root");
	testTree->Insert("2", "Root");
	testTree->Insert("3", "Root");
	testTree->Insert("4", "1");
	testTree->Insert("5", "2");
	testTree->Insert("6", "3");
	//2중 부모파트
	testTree->Insert("7", "3");
	testTree->Insert("7", "4");
	//
	testTree->Insert("8", "5");
	testTree->Insert("9", "6");
	testTree->Insert("10", "7");

}