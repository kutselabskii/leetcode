#include <iostream>
#include <vector>
using namespace std;

#include "743_NetworkDelayTime.hpp"

int main()
{
	vector<vector<int>> l = { {2, 1, 1}, {2, 3, 1}, {3, 4, 1} };
	cout << networkDelayTime(l, 4, 2) << endl;

	cin.get();
	return 0;
}

