// Source: https://leetcode.com/problems/binary-tree-level-order-traversal/
// Date: 2021/7/11
// Constraints: The number of nodes in the tree is in the range [0, 2000].

#include<iostream>
#include<vector>
#include<queue>
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
    queue<TreeNode *>myQue;
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        ans.push_back({root->val});
        if(root->left)
            myQue.push(root->left);
        if(root->right)
            myQue.push(root->right);
        while(!myQue.empty()) {
            int sz = myQue.size();
            vector<int>t;
            for(int i=0; i<sz; i++) {
                TreeNode* curNode = myQue.front();
                myQue.pop();
                t.push_back(curNode->val);
                if(curNode->left)
                    myQue.push(curNode->left);
                if(curNode->right)
                    myQue.push(curNode->right);
            }
            ans.push_back(t);
        }
        return ans;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();