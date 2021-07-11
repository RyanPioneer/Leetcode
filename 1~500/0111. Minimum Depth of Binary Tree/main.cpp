// Source: https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Date: 2021/7/9

#include<iostream>
#include<queue>
#include<utility>
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
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<pair<TreeNode*, int> >myQue;
        myQue.push(make_pair(root, 1));
        int dis = 1;
        while(!myQue.empty()) {
            TreeNode* curNode = myQue.front().first;
            dis = myQue.front().second;
            myQue.pop();
            if(curNode->left == NULL && curNode->right == NULL)
                return dis;
            if(curNode->left != NULL)
                myQue.push(make_pair(curNode->left, dis+1));
            if(curNode->right != NULL)
                myQue.push(make_pair(curNode->right, dis+1));
        }
        return dis;
    }
};