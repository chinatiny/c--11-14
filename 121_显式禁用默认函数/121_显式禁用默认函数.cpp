#include <iostream>


class Magic
{
public:
	Magic() {}
	~Magic(){}
	
	//��ֹʹ�ÿ�������͵ȺŸ�ֵ����֮ǰ����ΪprivateȨ�޾������
	Magic(const Magic& magic) = delete;
	Magic& operator =(const Magic &magic) = delete;

};


int main(int argc, char* argv[])
{
	Magic a;
	Magic b;
	//Magic c(a);  // ��ʱ��û�����п���������
	//a = b;   // ��ʱ��û������=����
	return 0;
}