// Source: https://leetcode.com/problems/path-sum/
// Date: 2021/7/11
// The number of nodes in the tree is in the range [0, 5000].
// -1000 <= Node.val <= 1000
// -1000 <= targetSum <= 1000

#include<iostream>
using namespace std;


// Definition for a binary tree node.
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        if(!(root->left) && !(root->right))
            return root->val == targetSum;
        if(root->left) 
            root->left->val = root->val + root->left->val;
        if(root->right) 
            root->right->val = root->val + root->right->val;
        return (hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum));
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

