#pragma once

#include <unordered_set>

// Time: O(log(n)) in worst case, usually faster
// Memory: O(1)

int brianKernighan(int number)
{
	int count = 0;
	while (number != 0) {
		count++;
		number &= number - 1;
	}

	return count;
}

int countPrimeSetBits(int left, int right)
{
	std::unordered_set<int> primes({ 2, 3, 5, 7, 11, 13, 17, 19 });
	int result = 0;

	for (int i = left; i <= right; ++i) {
		if (primes.find(brianKernighan(i)) != primes.end()) {
			result++;
		} 
	}

	return result;
}