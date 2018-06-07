#include "Test.h"

int add(int a, int b)
{
	std::cout << "add" << std::endl;
	return a + b;
}

class TestAdd
{
public:
	int Add(int a, int b)
	{
		std::cout << "TestAdd::Add" << std::endl;
		return a + b;
	}
};

/*
分析：
	使用：std::function<int(int, int)> fun 作为参数
	使用：std::bind(&TestAdd::Add, testAdd, std::placeholders::_1, std::placeholders::_2) 生产出函数指针
	std::placeholders::_1: 占位符1
	std::placeholders::_2: 占位符2



好处：
	可以把一个类的成员函数和对象传递过去，可以跨__cdecl和__thiscall
*/


// 用来测试bind
int TestBind(int a, int b, int c)
{
	return a + b + c;
}


int main()
{
	Test test;
	test.Add(add, 1, 2);

	TestAdd testAdd;
	test.Add(std::bind(&TestAdd::Add, testAdd, std::placeholders::_1, std::placeholders::_2), 1, 2);

	
	auto fnTestBind=std::bind(TestBind, 3, std::placeholders::_1, 9);
	auto ret = fnTestBind(1);
	std::cout << "ret: " << ret << std::endl;
	return 0;
}