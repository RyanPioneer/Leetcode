// Source: https://leetcode.com/problems/balanced-binary-tree/
// Date: 2021/7/9

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    bool helper(TreeNode* root, int &height) {
        if(!root) {
            height = 0;
            return true;
        }
        int l_h = -1, r_h = -1; // Note!
        if(helper(root -> left, l_h) && helper(root -> right, r_h)) {
            height = 1 + max(l_h, r_h);
            return abs(l_h - r_h) <= 1;
        }
        return false;
    }
public:
    bool isBalanced(TreeNode* root) {
        int height = -1;
        return helper(root, height);
    }
};
