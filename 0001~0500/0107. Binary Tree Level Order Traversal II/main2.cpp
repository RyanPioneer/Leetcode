// Source: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Date: 2021/7/11
// Constraints: The number of nodes in the tree is in the range [0, 2000].

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(level == res.size())
                res.push_back(vector<int>());
            res[level].push_back(node->val);
            if(node->left)
                q.push(make_pair(node->left, level + 1 ));
            if(node->right)
                q.push(make_pair(node->right, level + 1 ));
        }
        reverse(res.begin(), res.end());
        return res;
    }
};