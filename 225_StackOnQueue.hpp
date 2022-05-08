#pragma once

#include <queue>

class MyStack
{
public:
	std::queue<int> data;

	MyStack()
	{
		data = std::queue<int>();
	}

	void push(int x)
	{
		const size_t size = data.size();
		data.push(x);
		for (size_t i = 0; i < size; ++i) {
			data.push(pop());
		}
	}

	int pop()
	{
		auto result = data.front();
		data.pop();
		return result;
	}

	int top()
	{
		return data.front();
	}

	bool empty()
	{
		return data.empty();
	}
};