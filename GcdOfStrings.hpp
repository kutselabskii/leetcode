#pragma once
#include <string>

// Time: O(M), M is the shortest string length
// Memory: O(M)

bool isPattern(std::string original, std::string prefix)
{
	size_t position = 0;
	while (position < original.length()) {
		if (original.find(prefix, position) != position) {
			return false;
		}

		position += prefix.length();
	}

	return position == original.length();
}

std::string gcdOfStrings(std::string str1, std::string str2)
{
	const std::string smaller = str1.length() < str2.length() ? str1 : str2;
	const std::string bigger = str1.length() < str2.length() ? str2 : str1;

	std::string pattern;

	for (size_t i = 1; i <= smaller.length(); ++i) {
		if (smaller.length() % i != 0 || bigger.length() % i != 0) {
			continue;
		}

		const std::string current = smaller.substr(0, i);

		if (isPattern(smaller, current) && isPattern(bigger, current)) {
			pattern = current;
		}
	}

	return pattern;
}