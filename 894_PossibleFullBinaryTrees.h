#pragma once

#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_map<int, vector<TreeNode*>> cache;

vector<TreeNode*> allPossibleFBT(int n)
{
    if (cache.find(n) != cache.end()) {
        return cache[n];
    }

    vector<TreeNode*> result;

    if (n == 1) {
        result.push_back(new TreeNode());;
    } else if (n % 2 == 1) {
        for (int i = 0; i < n; ++i) {
            int j = n - 1 - i;
            for (auto left : allPossibleFBT(i)) {
                for (auto right : allPossibleFBT(j)) {
                    TreeNode* node = new TreeNode();
                    node->left = left;
                    node->right = right;
                    result.push_back(node);
                }
            }
        }
    }

    cache[n] = result;
    return result;
}
 