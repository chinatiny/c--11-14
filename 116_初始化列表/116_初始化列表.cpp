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

	//�������ʹ���˳�ʼ���б�
	std::vector<int> vecTmp = { 1, 2, 3, 4, 5, 6 };

	//�����Լ�ʹ�ó�ʼ���б�ĵط�
	MagicFoo magicFoo = { 5, 2, 3, 7, 9, 100 };
	magicFoo.ShowMagic();

	return 0;
}