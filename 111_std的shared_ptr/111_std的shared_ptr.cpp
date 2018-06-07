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

	//���������ü���Ϊ1
	std::cout << "1 ref:" << p1.use_count() << std::endl;


	{
		//���������ü���Ϊ2
		std::shared_ptr<Test> p2 = p1;
		std::cout << "2 ref:" << p1.use_count() << std::endl;
	}


	//��Ϊp2�������ŵ����������ü����ֱ�Ϊ1
	std::cout << "3 ref:" << p1.use_count() << std::endl;

	return 0;
}