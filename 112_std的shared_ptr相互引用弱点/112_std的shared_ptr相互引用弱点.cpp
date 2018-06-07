#include <iostream>
#include <memory>


class TestB;
class TestA
{
public:
	TestA()
	{
		std::cout << "TestA()" << std::endl;
	}
	void ReferTestB(std::shared_ptr<TestB> test_ptr)
	{
		m_TestB_Ptr = test_ptr;
	}
	~TestA()
	{
		std::cout << "~TestA()" << std::endl;
	}
private:
	std::shared_ptr<TestB> m_TestB_Ptr; //TestB������ָ��
};

class TestB
{
public:
	TestB()
	{
		std::cout << "TestB()" << std::endl;
	}

	void ReferTestB(std::shared_ptr<TestA> test_ptr)
	{
		m_TestA_Ptr = test_ptr;
	}
	~TestB()
	{
		std::cout << "~TestB()" << std::endl;
	}
	std::shared_ptr<TestA> m_TestA_Ptr; //TestA������ָ��
};


/*
Ҫ�㣺
	1. ����ĳ�Ա���������ںͶ���ͬʱ���ڵ�
	2. main�������������ڣ���main����ִ�����
	3. new�����Ķ������ִ��delete�ſ���ִ������
*/



/*
���������
	1. ��ִ�����������д��룺
			std::shared_ptr<TestA> ptr_a = std::make_shared<TestA>();
			std::shared_ptr<TestB> ptr_b = std::make_shared<TestB>();
	   ��shared_ptr�ڲ�����new�ķ�ʽ������TestA��TestB
	   ptr_a��ptr_b��������ü�����Ϊ1

	2. ִ������������
		ptr_a->ReferTestB(ptr_b);
		ptr_b->ReferTestB(ptr_a);
		std::shared_ptr<TestA>��std::shared_ptr<TestB>�ֱ�����˿������캯����ptr_a��ptr_b��������ü�����Ϊ2

	3. ��main����ִ�����ʱ��
	    ptr_aִ����������������ʱ�������ü�������Ϊ2��û��delete TestA������TestAû��ִ������
		ptr_bִ����������������ʱ�������ü�������Ϊ2��û��delete TestB������TestBû��ִ������
*/


int main()
{
	std::shared_ptr<TestA> ptr_a = std::make_shared<TestA>();
	std::shared_ptr<TestB> ptr_b = std::make_shared<TestB>();
	ptr_a->ReferTestB(ptr_b);
	ptr_b->ReferTestB(ptr_a);

	return 0;
}