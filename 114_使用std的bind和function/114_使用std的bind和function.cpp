#include "Test.h"

int add(int a, int b)
{
	std::cout << "add" << std::endl;
	return a + b;
}

class TestAdd
{
public:
	int Add(int a, int b)
	{
		std::cout << "TestAdd::Add" << std::endl;
		return a + b;
	}
};

/*
������
	ʹ�ã�std::function<int(int, int)> fun ��Ϊ����
	ʹ�ã�std::bind(&TestAdd::Add, testAdd, std::placeholders::_1, std::placeholders::_2) ����������ָ��
	std::placeholders::_1: ռλ��1
	std::placeholders::_2: ռλ��2



�ô���
	���԰�һ����ĳ�Ա�����Ͷ��󴫵ݹ�ȥ�����Կ�__cdecl��__thiscall
*/


// ��������bind
int TestBind(int a, int b, int c)
{
	return a + b + c;
}


int main()
{
	Test test;
	test.Add(add, 1, 2);

	TestAdd testAdd;
	test.Add(std::bind(&TestAdd::Add, testAdd, std::placeholders::_1, std::placeholders::_2), 1, 2);

	
	auto fnTestBind=std::bind(TestBind, 3, std::placeholders::_1, 9);
	auto ret = fnTestBind(1);
	std::cout << "ret: " << ret << std::endl;
	return 0;
}