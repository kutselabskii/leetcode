#pragma once

#include <string>
#include <stack>
using namespace std;

// Time: O(n)
// memory: O(n)

int longestValidParentheses(string s)
{
    stack<int> container;
    int result = 0;

    container.push(-1);
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            container.push(i);
        } else {
            container.pop();
            if (container.empty()) {
                container.push(i);
            } else {
                result = max(result, i - container.top());
            }
        }
    }
    return result;
}