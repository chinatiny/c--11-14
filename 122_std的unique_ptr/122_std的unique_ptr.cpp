#include <iostream>
#include <memory>


struct  Foo
{
	Foo()
	{
		std::cout << "Foo::Foo" << std::endl;
	}
	~Foo()
	{
		std::cout << "Foo::~Foo" << std::endl;
	}
	void foo()
	{
		std::cout << "Foo::foo" << std::endl;
	}
};


void f(const Foo &foo)
{
	std::cout << "f(const Foo&)" << std::endl;
}

int main(int argc, char* argv[])
{
	std::unique_ptr<Foo> p1 = std::make_unique<Foo>();

	//p1 ��Ϊ�գ����
	if (p1)
	{
		p1->foo();
	}

	{
		std::unique_ptr<Foo> p2 = std::move(p1);

		//�������
		f(*p2);

		//�������
		if (p2)
		{
			p2->foo();
		}

		//p1Ϊ�գ������
		if (p1)
		{
			p1->foo();
		}

		p1 = std::move(p2);
		//p2Ϊ�������
		if (p2)
		{
			p2->foo();
		}

		std::cout << "p2 ������" << std::endl;
	}

	// p1 ���գ����
	if (p1)
	{
		p1->foo();
	}




	return 0;
}