#include <iostream>


auto AddTest(int a, int b)
{
	return a + b;
}


/*
	注意：
		1. auto 不能用于参数传递
		2. auto 不能推倒数组类型
*/

int main(int argc, char* argv[])
{

	auto index = 10;
	auto str = "abc";
	auto ret = AddTest(1, 2);
	std::cout << "index:" << index << std::endl;
	std::cout << "str:" << str << std::endl;
	std::cout << "res:" << ret << std::endl;

	return 0;
}
