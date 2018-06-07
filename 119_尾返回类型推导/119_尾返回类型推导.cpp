#include <iostream>


//1. 通过模板定义一个模板函数
template<typename R, typename T, typename U>
R add1(T a, U b)
{
	return a + b;
}

//2. 通过类型推导返回，仅仅在c++ 14中的用法
template<typename T, typename U>
decltype(a + b) add2(T a, U b)
{
	return a + b;
}


//3. 通过尾返回类型，仅仅在c++11中的用法
template<typename T, typename U>
auto Add3(T a, U b)
{
	return a + b;
}


int main(int argc, char* argv[])
{
	auto add3Ret = Add3<int, float>(2, 3.4f);

	std::cout << "add3Ret:" << add3Ret << std::endl;


	if (std::is_same<decltype(add3Ret), float>::value)
	{
		std::cout << "decltype(add3Ret) == float" << std::endl;
	}

	return 0;
}