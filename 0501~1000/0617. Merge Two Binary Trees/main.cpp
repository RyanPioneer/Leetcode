// Source: https://leetcode.com/problems/merge-two-binary-trees/
// Date: 2021/7/9

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

//if two nodes overlap, then sum node values up as the new value of the merged node.

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL)
            return root2;
        if(root2 == NULL)
            return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

/*static auto x = []() { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
};*/