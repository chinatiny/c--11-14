#include <iostream>
#include <string>
#include <tuple>


std::tuple<int, std::string, double>  foo()
{
	return std::make_tuple(3, "this a tuple", 3.14);
}

int main(int argc, char* argv[])
{
	std::tuple<int, std::string, double> retTuple;
	retTuple = foo();

	//1. ʹ��tie��ȡֵ
	int n;
	std::string str;
	double d;
	std::tie(n, str, d) = retTuple;

	std::cout << "n:" << n << "  str:" << str << "  d:" << d << std::endl;


	//2. ʹ��get
	std::cout << "n:" << std::get<0>(retTuple) << "  str:" << std::get<1>(retTuple) << "  d:" << std::get<2>(retTuple) << std::endl;

	return 0;
}