#include <iostream>


auto AddTest(int a, int b)
{
	return a + b;
}


/*
	ע�⣺
		1. auto �������ڲ�������
		2. auto �����Ƶ���������
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
