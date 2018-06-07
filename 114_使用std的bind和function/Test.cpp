#include "Test.h"



void Test::Add(std::function<int(int, int)> fun, int a, int b)
{
	int sum = fun(a, b);
	std::cout << "sum:" << sum << std::endl;
}

