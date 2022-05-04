#include <iostream>
#include <vector>

#include "1238_GrayCode.hpp"

int main()
{

	auto result = circularPermutation(3, 2);
	for (auto v : result) {
		std::cout << v << " ";
	}
	std::cin.get();
	return 0;
}

