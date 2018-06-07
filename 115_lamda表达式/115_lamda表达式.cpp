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

lamda 表达式：
	[]：捕捉列表。捕捉列表总是出现在Lambda函数的开始处
	(int a, int b)：括号里面是参数
	->int：int代表返回类型

关于捕获列表：
	[var]表示值传递方式捕捉变量var；
	[=]表示值传递方式捕捉所有父作用域的变量（包括this）；
	[&var]表示引用传递捕捉变量var；
	[&]表示引用传递方式捕捉所有父作用域的变量（包括this）；
	[this]表示值传递方式捕捉当前的this指针。

关于闭包：
	定义：闭包就是能够读取其他函数内部变量的函数。
	实现原理：通过lamda表达式中的捕获列表实现

好处：
	可以把一个类的成员函数和对象传递过去，可以跨__cdecl和__thiscall
*/


int main()
{
	Test test;
	test.Add(add, 1, 2);

	TestAdd testAdd;
	test.Add(std::bind(&TestAdd::Add, testAdd, std::placeholders::_1, std::placeholders::_2), 1, 2);

	// lamda使用例子1
	test.Add([](int a, int b)->int {
		std::cout << "lamda add fun" << std::endl;
		return a + b;
	}, 1, 2);

	// lamda使用例子2,闭包
	int a = 10;
	int vec[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	auto func = [&a](int v) {std::cout << v + a << std::endl; };
	for (auto i : vec)
	{
		func(i);
		++a;
	}

	return 0;
}