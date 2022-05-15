#pragma once

#include <vector>
#include <unordered_set>

// Time: O(n)
// Memory: O(1), but we need 500k elements bool array

int firstMissingPositive(std::vector<int>& nums)
{
	const int maxAmount = 500000 + 1;

	bool metValues[maxAmount] = {false};

	for (int& num : nums) {
		if (num < 0 || num >= maxAmount) {
			continue;
		}

		metValues[num] = true;
	}

	for (int i = 1; i < maxAmount; ++i) {
		if (metValues[i] == false) {
			return i;
		}
	}

	return maxAmount;
}