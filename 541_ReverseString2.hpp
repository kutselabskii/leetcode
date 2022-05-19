#pragma once

#include <string>
#include <algorithm>
using namespace std;

// Time: O(n)
// Memory: O(1) (almost no additional memory)

string reverseStr(string s, int k)
{  
    int i = 0;
    while (i < s.length()) {
        int start = i;
        int end = min<int>(s.length() - 1, i + k - 1);
        while (start < end) {
            char c = s[start];
            s[start] = s[end];
            s[end] = c;
            
            start++;
            end--;
        }
        i += 2 * k;
    }
    return s;
}