// Source: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
// Date: 2021/7/9

#include<iostream>
#include<cstdlib>  // for abs
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
    int nodes[10001];
    int len = 0;
    int ans = 100001;
    int getMinimumDifference(TreeNode* root) {
        makeTree(root);
        for(int i=0; i<len-1; i++) {
            if(abs(nodes[i]-nodes[i+1]) < ans)
                ans = abs(nodes[i]-nodes[i+1]);
        }
        return ans;
    }

    void makeTree(TreeNode* root) {
        if(!root)
            return;
        if(root->left)
            makeTree(root->left);
        nodes[len++] = root->val;
        if(root->right)
            makeTree(root->right);
    }
};

// make program run much faster!!
// https://blog.csdn.net/qq_32320399/article/details/81518476
//static auto _ = [](){ ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();