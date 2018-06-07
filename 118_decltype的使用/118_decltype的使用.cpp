#include <iostream>

int main(int argc, char* argv[])
{
	auto x = 1;
	auto y = 2;
	decltype(x + y) z = x + y;

	if (std::is_same<decltype(x), int>::value)
	{
		std::cout << "type x == int" << std::endl;
	}
	if (std::is_same<decltype(x), float>::value)
	{
		std::cout << "type x == float" << std::endl;
	}
	if (std::is_same<decltype(x), decltype(z)>::value)
	{
		std::cout << "type x == type z" << std::endl;
	}



	return 0;
}