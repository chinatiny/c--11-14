#include <iostream>
#include <memory>

class Test
{
public:
	Test()
	{
		std::cout << "Test()" << std::endl;
	}
	~Test()
	{
		std::cout << "~Test()" << std::endl;
	}
};

int main(int argc, char* argv[])
{
	std::shared_ptr<Test> p1 = std::make_shared<Test>();

	//在这里引用计数为1
	std::cout << "1 ref:" << p1.use_count() << std::endl;


	{
		//在这里引用计数为2
		std::shared_ptr<Test> p2 = p1;
		std::cout << "2 ref:" << p1.use_count() << std::endl;
	}


	//因为p2除了括号的作用域引用计数又变为1
	std::cout << "3 ref:" << p1.use_count() << std::endl;

	return 0;
}