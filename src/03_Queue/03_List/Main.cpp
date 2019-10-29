#include "TList.h"

int main()
{
	TList<int, int> test;
	int* a = new int;
	*a = 100;
	test.InstertForward(10, a);
	return 0;
}