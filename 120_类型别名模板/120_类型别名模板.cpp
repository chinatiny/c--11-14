#include <iostream>
#include <vector>

template <typename T, typename U>

class MagicType
{
public:
	T dark;
	U magic;
};


// 1. 错误做法
//template <typename T>
//typedef MagicType<std::vector<T>, std::string> FakeDarkMagic;




//2. 正确的做法，c++11后使用using 引入了下面这种形式的写法，并且执行对传统typedef 相同的功效功能

//比如定义函数
typedef int(*fpnTypeNewprocess1)(void*);

using fpnTypeNewprocess2 = int(*)(void *);

//比如定义类型别名模板
template <typename T>
using TrueDarkMagic = MagicType<std::vector<T>, std::string>;


int main(int argc, char* argv[])
{
	TrueDarkMagic<bool>  magic;
	return 0;
}