#pragma once

#include <string>
#include <vector>
#include <unordered_map>

// Time: N + M
// Memory: N + M

void countWords(const std::vector<std::string>& words, std::unordered_map<std::string, int>& map)
{
	for (const auto &word : words) {
		map.try_emplace(word, 0);
		map[word]++;
	}
}

int countWords(std::vector<std::string>& words1, std::vector<std::string>& words2)
{
	std::unordered_map<std::string, int> metWords1;
	std::unordered_map<std::string, int> metWords2;

	countWords(words1, metWords1);
	countWords(words2, metWords2);

	int result = 0;
	for (const auto &pair : metWords1) {
		if (metWords2.count(pair.first) > 0 && pair.second + metWords2[pair.first] == 2) {
			result++;
		}
	}

	return result;
}