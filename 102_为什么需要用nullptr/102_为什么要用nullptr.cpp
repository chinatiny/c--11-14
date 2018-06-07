#include <iostream>

class Test
{
public:
	void TestFunc(int nIndex)
	{
		std::cout << "this is TestFunc1" << std::endl;
	}

	void TestFunc(int *pnIndex)
	{
		std::cout << "this is TestFun2" << std::endl;
	}
};


int main(int argc, char* argv[])
{
	Test test;
	test.TestFunc(NULL);
	test.TestFunc(nullptr);

	return 0;
}