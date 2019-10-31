#include "TList.h"

int main()
{
	TList<int, int> test;
	int* a = new int;
	*a = 100;
	test.InsertBackward(1, a);
	test.InsertBackward(2, a);
	test.InsertBackward(3, a);
	test.Reset();
	test.Next();
	test.Remove(1);
	test.Remove(3);
	return 0;
}