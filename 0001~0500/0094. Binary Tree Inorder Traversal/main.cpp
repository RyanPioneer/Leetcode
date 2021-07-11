// Source: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Date: 2021/7/9

#include<iostream>
#include<vector>
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
    vector<int>ans;
    vector<int> inorderTraversal(TreeNode* root) {
        preOrder(root);
        return ans;
    }

    void preOrder(TreeNode* root) {
        if(!root)
            return;
        if(root->left)
            preOrder(root->left);
        ans.push_back(root->val);
        if(root->right)
            preOrder(root->right);
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
