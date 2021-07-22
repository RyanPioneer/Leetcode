/** 
 * Source: https://leetcode.com/problems/all-possible-full-binary-trees/
 * Date: 2021/7/22
 * Skill: DP
 * Runtime: 80 ms, faster than 92.70% of C++ online submissions
 * Memory Usage: 28.8 MB, less than 67.76% of C++ online submissions 
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 * 
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//* Definition for a binary tree node.
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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> dp(n+1);
        dp[1] = {new TreeNode(0)};
        for (int i = 1; i <= n; i+=2) {
            for (int j = 1; j <= i-2; j+=2) {
                for (auto k: dp[j]) {
                    for (auto l:dp[i-j-1]) {
                        TreeNode *root = new TreeNode(0);
                        root->left = k;
                        root->right = l;
                        dp[i].push_back(root);
                    }
                }
            }
        }
        return dp[n];  
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();