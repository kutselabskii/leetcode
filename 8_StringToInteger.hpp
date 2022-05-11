#pragma once

#include <string>
#include <algorithm>
#include <limits>

// Time: O(n)
// Memory: O(1)

int myAtoi(std::string s)
{
	size_t position = s.find_first_not_of(' ');

	if (position == -1) {
		return 0;
	}

	int sign = 1;
	if (s[position] == '+') {
		sign = 1;
		position++;
	} else if (s[position] == '-') {
		sign = -1;
		position++;
	}

	int result = 0;

	constexpr int maxValue = std::numeric_limits<int>::max();
	constexpr int minValue = std::numeric_limits<int>::min();
	while (position < s.length() && s[position] >= '0' && s[position] <= '9') {
		int currentDigit = (s[position] - '0') * sign;
		if (sign == 1 && (maxValue - currentDigit) / 10 < result) {
			return maxValue;
		}

		if (sign == -1 && (minValue - currentDigit) / 10 > result) {
			return minValue;
		}

		result = result * 10 + currentDigit;

		position++;
	}

	return result;
}