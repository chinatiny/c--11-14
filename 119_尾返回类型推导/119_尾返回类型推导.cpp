#include <iostream>


//1. ͨ��ģ�嶨��һ��ģ�庯��
template<typename R, typename T, typename U>
R add1(T a, U b)
{
	return a + b;
}

//2. ͨ�������Ƶ����أ�������c++ 14�е��÷�
template<typename T, typename U>
decltype(a + b) add2(T a, U b)
{
	return a + b;
}


//3. ͨ��β�������ͣ�������c++11�е��÷�
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