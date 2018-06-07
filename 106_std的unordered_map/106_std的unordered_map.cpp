#include <iostream>
#include <unordered_map>
#include <string>

int main(int argc, char* argv)
{
	std::unordered_map<std::string, std::string> mapTest = 
	{
		{"name:", "hzh01"},
		{"age:", "18"},
		{"home:", "guodihu"}
	};


	unsigned int n = mapTest.bucket_count();
	std::cout << "mymap has " << n << " buckets.\n";

	for (unsigned i = 0; i < n; ++i)
	{
		std::cout << "bucket #" << i << " contains: ";
		for (auto it = mapTest.begin(i); it != mapTest.end(i); ++it)
			std::cout << "[" << it->first << ":" << it->second << "] ";
		std::cout << "\n";
	}


	return 0;
}