#pragma once
#include <functional>
#include <iostream>


class Test
{
public:
	void Add(std::function<int(int, int)> fun, int a, int b);
};
