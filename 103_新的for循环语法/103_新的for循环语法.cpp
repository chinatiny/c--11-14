#include <iostream>

int main(int argc, char* argv[])
{
	int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for (auto num : numbers)
	{
		std::cout << "num:" << num << std::endl;
	}
	return 0;
}