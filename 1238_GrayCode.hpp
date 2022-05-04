#pragma once

#include <vector>

// Time: O(2^n)
// Memory: O(2^n)

std::vector<int> make_gray_sequence(int n)
{
	std::vector<int> result(1 << n);

	for (int i = 0; i < 1 << n; ++i) {
		result[i] = i ^ (i >> 1);
	}

	return result;
}

std::vector<int> circularPermutation(int n, int start)
{
	std::vector<int> gray = make_gray_sequence(n);

	if (gray[0] != start) {
		const auto position = std::find(gray.begin(), gray.end(), start);
		std::rotate(gray.begin(), position, gray.end());
	}
	

	return gray;
}