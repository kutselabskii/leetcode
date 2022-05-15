#include <iostream>
#include <vector>

#include "41_FirstMissingPositive.hpp";

int main()
{
	std::vector<int> data = { 1, 2, 3 };

	std::cout << firstMissingPositive(data) << std::endl;

	std::cin.get();
	return 0;
}

