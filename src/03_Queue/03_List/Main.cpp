#include "TList.h"

int main()
{
	TList<int, int> test;
	int a = 100;
	test.InsertBackward(1, &a);
	test.InsertBackward(2, &a);
	test.InsertBackward(3, &a);
	test.Reset();
	TList<int, int> copy(test);
	return 0;
}