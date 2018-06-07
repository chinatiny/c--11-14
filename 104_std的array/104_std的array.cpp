#include <iostream>
#include <array>

int main(int argc, char* argv)
{
	std::array<int, 4> arry = { 1, 2, 3, 4 };

	for (auto ite :arry)
	{
		std::cout << "ite:" << ite << std::endl;
	}

	int size = sizeof(arry);
	std::cout << "size is:" << size << std::endl;

	return 0;
}