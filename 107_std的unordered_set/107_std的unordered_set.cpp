#include <iostream>
#include <unordered_set>
#include <string>

int main(int argc, char* argv)
{
	std::unordered_set<int> unorder_set;
	unorder_set.insert(7);
	unorder_set.insert(5);
	unorder_set.insert(3);
	unorder_set.insert(4);
	unorder_set.insert(6);
	std::cout << "unorder_set:" << std::endl;
	for (auto itor : unorder_set)
	{
		std::cout << itor << std::endl;
	}
	return 0;
}