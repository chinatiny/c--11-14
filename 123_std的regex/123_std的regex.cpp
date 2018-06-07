#include <iostream>
#include <string>
#include <regex>

int main(int argc, char* argv[])
{
	std::string fileNames[] =
	{
		"foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt"
	};

	std::cout << "-----------------����Ƿ�ƥ��" << std::endl;
	//����Ƿ�ƥ��,��������true����false
	std::cout << "����Ƿ�ƥ��" << std::endl;
	std::regex txtRegx("[A-z]+\\.txt");
	for (auto &fileName : fileNames)
	{
		std::cout << fileName << ": "<<std::regex_match(fileName, txtRegx) << std::endl;
	}


	std::cout << "-----------------���ƥ�䣬���Ұ�ƥ��Ĳ��ֳ�ȡ����" << std::endl;
	//���ƥ�䣬���Ұ�ƥ��Ĳ��ֳ�ȡ����
	std::regex txtBaseRegex("([A-z]+)\\.txt");
	std::smatch baseMatch;  // same as std::match_results<string::const_iterator> sm;  
	for (auto &fileName : fileNames)
	{
		if (std::regex_match(fileName, baseMatch, txtBaseRegex))
		{
			std::cout << "fule name: " << baseMatch[0] << std::endl;    // ��һ����������
			std::cout << "match Part: " << baseMatch[1] << std::endl;   //�ڶ������ǵ�һ��С�������������
		}	
	}


	std::cout << "-----------------�����ַ�����ƥ��" << std::endl;
	std::string s("subject");
	std::regex e("(sub)(.*)");
	std::cmatch cm;    // same as std::match_results<const char*> cm;  
	std::regex_match("subject", cm, e);
	std::cout << "string match part 0 " << cm[0] << std::endl;
	std::cout << "string match part 1 " << cm[1] << std::endl;
	std::cout << "string match part 2 " << cm[2] << std::endl;


	return 0;
}