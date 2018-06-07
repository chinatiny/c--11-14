#include <iostream>
#include <initializer_list>
#include <vector>

class MagicFoo 
{
public:
	std::vector<int> m_vec;
	MagicFoo(std::initializer_list<int> initializerList)
	{
		for (auto ite : initializerList)
		{
			m_vec.push_back(ite);
		}
	}

	void ShowMagic()
	{
		for (auto ite : m_vec)
		{
			std::cout << "vec element: " << ite << std::endl;
		}
	}
};

int main(int argc, char* argv[])
{

	//这个就是使用了初始化列表
	std::vector<int> vecTmp = { 1, 2, 3, 4, 5, 6 };

	//我们自己使用初始化列表的地方
	MagicFoo magicFoo = { 5, 2, 3, 7, 9, 100 };
	magicFoo.ShowMagic();

	return 0;
}