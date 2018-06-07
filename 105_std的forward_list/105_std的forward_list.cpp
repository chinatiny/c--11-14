#include <iostream>
#include <forward_list>

int main(int argc, char* argv)
{
	std::forward_list<int> forwardList = {1, 2, 3, 4};
	forwardList.remove(4);


	for (auto ite : forwardList)
	{
		std::cout << "fordlist:" << ite << std::endl;
	}

	return 0;
}