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

lamda ���ʽ��
	[]����׽�б���׽�б����ǳ�����Lambda�����Ŀ�ʼ��
	(int a, int b)�����������ǲ���
	->int��int����������

���ڲ����б�
	[var]��ʾֵ���ݷ�ʽ��׽����var��
	[=]��ʾֵ���ݷ�ʽ��׽���и�������ı���������this����
	[&var]��ʾ���ô��ݲ�׽����var��
	[&]��ʾ���ô��ݷ�ʽ��׽���и�������ı���������this����
	[this]��ʾֵ���ݷ�ʽ��׽��ǰ��thisָ�롣

���ڱհ���
	���壺�հ������ܹ���ȡ���������ڲ������ĺ�����
	ʵ��ԭ��ͨ��lamda���ʽ�еĲ����б�ʵ��

�ô���
	���԰�һ����ĳ�Ա�����Ͷ��󴫵ݹ�ȥ�����Կ�__cdecl��__thiscall
*/


int main()
{
	Test test;
	test.Add(add, 1, 2);

	TestAdd testAdd;
	test.Add(std::bind(&TestAdd::Add, testAdd, std::placeholders::_1, std::placeholders::_2), 1, 2);

	// lamdaʹ������1
	test.Add([](int a, int b)->int {
		std::cout << "lamda add fun" << std::endl;
		return a + b;
	}, 1, 2);

	// lamdaʹ������2,�հ�
	int a = 10;
	int vec[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	auto func = [&a](int v) {std::cout << v + a << std::endl; };
	for (auto i : vec)
	{
		func(i);
		++a;
	}

	return 0;
}