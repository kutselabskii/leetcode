#pragma once

#include <vector>
#include <unordered_set>

// Time: O(n)
// Memory: O(1), not using additional arrays

int firstMissingPositive(std::vector<int>& nums)
{
	int n = nums.size();
	for (int i = 0; i < n; ++i) {
		if (nums[i] <= 0) {
			nums[i] = n + 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0) {
			nums[abs(nums[i]) - 1] *= -1;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (nums[i] > 0) {
			return i + 1;
		}
	}

	return n + 1;
}