// Source: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Date: 2021/7/11
// Constraints: inorder and postorder consist of unique values.

#include<iostream>
#include<string>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }

    TreeNode* buildTree(vector<int>& inorder, int inorderL, int inorderR,
            vector<int>& postorder, int postorderL, int postorderR){
        if(inorderL >= inorderR)
            return NULL;
        if(inorderL + 1 == inorderR)
            return new TreeNode(inorder[inorderL]);
        TreeNode* root = new TreeNode(postorder[postorderR - 1]);
        int rootPos = find(inorder.begin() + inorderL, inorder.begin() + inorderR, root->val) - inorder.begin();
        int lsize = rootPos - inorderL;
        int rsize = inorderR - (rootPos + 1);
        root->left = buildTree(inorder, inorderL, inorderL + lsize, postorder, postorderL, postorderL + lsize);
        root->right = buildTree(inorder, rootPos + 1, inorderR, postorder, postorderL + lsize, postorderR - 1);
        return root;
    }
};