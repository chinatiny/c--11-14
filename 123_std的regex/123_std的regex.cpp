#include <iostream>
#include <string>
#include <regex>

int main(int argc, char* argv[])
{
	std::string fileNames[] =
	{
		"foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt"
	};

	std::cout << "-----------------检测是否匹配" << std::endl;
	//检测是否匹配,仅仅返回true或者false
	std::cout << "检测是否匹配" << std::endl;
	std::regex txtRegx("[A-z]+\\.txt");
	for (auto &fileName : fileNames)
	{
		std::cout << fileName << ": "<<std::regex_match(fileName, txtRegx) << std::endl;
	}


	std::cout << "-----------------检测匹配，并且把匹配的部分抽取出来" << std::endl;
	//检测匹配，并且把匹配的部分抽取出来
	std::regex txtBaseRegex("([A-z]+)\\.txt");
	std::smatch baseMatch;  // same as std::match_results<string::const_iterator> sm;  
	for (auto &fileName : fileNames)
	{
		if (std::regex_match(fileName, baseMatch, txtBaseRegex))
		{
			std::cout << "fule name: " << baseMatch[0] << std::endl;    // 第一部分是整体
			std::cout << "match Part: " << baseMatch[1] << std::endl;   //第二部分是第一个小括号里面的内容
		}	
	}


	std::cout << "-----------------单条字符串的匹配" << std::endl;
	std::string s("subject");
	std::regex e("(sub)(.*)");
	std::cmatch cm;    // same as std::match_results<const char*> cm;  
	std::regex_match("subject", cm, e);
	std::cout << "string match part 0 " << cm[0] << std::endl;
	std::cout << "string match part 1 " << cm[1] << std::endl;
	std::cout << "string match part 2 " << cm[2] << std::endl;


	return 0;
}