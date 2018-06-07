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
	std::shared_ptr<TestB> m_TestB_Ptr; //TestB的智能指针
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
	std::shared_ptr<TestA> m_TestA_Ptr; //TestA的智能指针
};


/*
要点：
	1. 对象的成员的生命周期和对象同时存在的
	2. main函数的生命周期，当main函数执行完毕
	3. new出来的对象必须执行delete才可以执行析构
*/



/*
问题分析：
	1. 当执行完下面两行代码：
			std::shared_ptr<TestA> ptr_a = std::make_shared<TestA>();
			std::shared_ptr<TestB> ptr_b = std::make_shared<TestB>();
	   在shared_ptr内部是以new的方式创建了TestA和TestB
	   ptr_a和ptr_b里面的引用计数都为1

	2. 执行完下面两行
		ptr_a->ReferTestB(ptr_b);
		ptr_b->ReferTestB(ptr_a);
		std::shared_ptr<TestA>和std::shared_ptr<TestB>分别调用了拷贝构造函数，ptr_a和ptr_b里面的引用计数都为2

	3. 当main函数执行完毕时候
	    ptr_a执行析构，在析构的时候检测引用计数发现为2，没法delete TestA，所以TestA没有执行析构
		ptr_b执行析构，在析构的时候检测引用计数发现为2，没法delete TestB，所以TestB没有执行析构
*/


int main()
{
	std::shared_ptr<TestA> ptr_a = std::make_shared<TestA>();
	std::shared_ptr<TestB> ptr_b = std::make_shared<TestB>();
	ptr_a->ReferTestB(ptr_b);
	ptr_b->ReferTestB(ptr_a);

	return 0;
}