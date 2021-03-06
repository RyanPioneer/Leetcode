// Source: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Date: 2021/7/11
// Constraints: preorder and inorder consist of unique values.

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
    int index = 0, i;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size() == 0) 
            return NULL;
        if(inorder.size() == 1) {
            TreeNode* curNode = new TreeNode(preorder[index++]);
            return curNode;
        }
        TreeNode* curNode = new TreeNode(preorder[index]);
        for(i = 0; i < inorder.size(); i++) {
            if(inorder[i] == preorder[index]) {
                index++;
                break;
            }
        }
        vector<int>leftHalf(inorder.begin(), inorder.begin()+i);
        vector<int>rightHalf(inorder.begin()+i+1, inorder.end());
        curNode->left = buildTree(preorder, leftHalf);
        curNode->right = buildTree(preorder, rightHalf);
        return curNode;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();