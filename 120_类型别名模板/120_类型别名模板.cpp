#include <iostream>
#include <vector>

template <typename T, typename U>

class MagicType
{
public:
	T dark;
	U magic;
};


// 1. ��������
//template <typename T>
//typedef MagicType<std::vector<T>, std::string> FakeDarkMagic;




//2. ��ȷ��������c++11��ʹ��using ����������������ʽ��д��������ִ�жԴ�ͳtypedef ��ͬ�Ĺ�Ч����

//���綨�庯��
typedef int(*fpnTypeNewprocess1)(void*);

using fpnTypeNewprocess2 = int(*)(void *);

//���綨�����ͱ���ģ��
template <typename T>
using TrueDarkMagic = MagicType<std::vector<T>, std::string>;


int main(int argc, char* argv[])
{
	TrueDarkMagic<bool>  magic;
	return 0;
}