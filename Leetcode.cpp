#include <iostream>
#include <vector>

#include "121_BuySellStocks.hpp"

int main()
{
	std::vector<int> prices{ 7,6,4,3,1 };
	std::cout << maxProfit(prices) << std::endl;
	std::cin.get();
	return 0;
}

