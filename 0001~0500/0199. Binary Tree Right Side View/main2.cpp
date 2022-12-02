/**
 * Source: https://leetcode.com/problems/binary-tree-right-side-view/
 * Date: 2022/7/11
 * Skill: Recursive
 * Runtime:
 * Memory Usage:
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        return solve(root, ans, 0);
    }

    vector<int> solve(TreeNode* root, vector<int> ans, int lvl) {
        if (!root)
            return ans;
        if (ans.size() == lvl)
            ans.push_back(root->val);
        ans = solve(root->right, ans, lvl+1);
        ans = solve(root->left, ans, lvl+1);
        return ans;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution s;
    vector<int> ans = s.rightSideView(root);
    for (auto i: ans)
        cout << i << " ";
    
    
}

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
