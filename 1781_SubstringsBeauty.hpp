#pragma once

// Time: O(N^2) + O(N)
// Memory: O(1)

#include <string>
#include <vector>
#include <algorithm>
#include <limits>

int beautySum(std::string s)
{
	int result = 0;

	for (size_t i = 0; i < s.length(); ++i) {
		std::vector<int> charCount(26, 0);
		for (size_t j = i; j < s.length(); ++j) {
			charCount[s[j] - 'a']++;

			int min = std::numeric_limits<int>::max();
			for (int& character : charCount) {
				if (character != 0) {
					min = std::min(min, character);
				} 
			}

			result += *std::max_element(charCount.begin(), charCount.end()) - min;
		}
	}

	return result;
}