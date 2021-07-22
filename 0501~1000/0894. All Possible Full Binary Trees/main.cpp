/** 
 * Source: https://leetcode.com/problems/all-possible-full-binary-trees/
 * Date: 2021/7/22
 * Skill: Recursion
 * Runtime: 112 ms, faster than 34.90% of C++ online submissions
 * Memory Usage: 38.3 MB, less than 25.29% of C++ online submissions 
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
        vector<TreeNode*> ans;
        if (n == 1) 
            ans.push_back(new TreeNode(0));
        else {
            if (n%2 == 0) return {};
            for (int i = 1; i <= n-2; i+=2) {
                if (i%2 == 1 && (n-i-1)%2 == 1) {
                    for (auto j:allPossibleFBT(i)) {
                        for (auto k:allPossibleFBT(n-i-1)) {
                            TreeNode* root = new TreeNode(0);
                            root->left = j;
                            root->right = k;
                            ans.push_back(root);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();