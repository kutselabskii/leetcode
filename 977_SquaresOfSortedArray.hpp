#pragma once

#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int>& nums)
{
	auto l = nums.cbegin();
	auto r = nums.cend() - 1;
	vector<int>result(nums.size());
	for (int k = nums.size() - 1; k >= 0; --k) {
		if (abs(*l) > abs(*r)) {
			result[k] = *l * *l;
			l++;
		} else {
			result[k] = *r * *r;
			r--;
		}
	}
	return result;
}
