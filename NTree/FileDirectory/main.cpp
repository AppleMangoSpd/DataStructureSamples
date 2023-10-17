#include "NTree.h"
#include "FileDirectory.h"
int main()
{
	FileDirectory* testFD = new FileDirectory();
	testFD->StartFileDirectory();

	delete testFD;
}