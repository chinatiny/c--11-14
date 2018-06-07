#include <iostream>


class Magic
{
public:
	Magic() {}
	~Magic(){}
	
	//禁止使用拷贝构造和等号赋值，比之前设置为private权限精简多了
	Magic(const Magic& magic) = delete;
	Magic& operator =(const Magic &magic) = delete;

};


int main(int argc, char* argv[])
{
	Magic a;
	Magic b;
	//Magic c(a);  // 这时就没法进行拷贝构造了
	//a = b;   // 这时就没法进行=号了
	return 0;
}