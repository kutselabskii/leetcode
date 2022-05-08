#pragma once

#include <vector>
#include <limits>

// Time: O(N)
// Memory: O(1)

int maxProfit(std::vector<int>& prices)
{
	int min = std::numeric_limits<int>::max();
	int best = 0;

	for (const int& price : prices) {
		const int current = price - min;
		if (current > best) {
			best = current;
		}

		if (price < min) {
			min = price;
		}
	}

	return best;
}