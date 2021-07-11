// Source: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Date: 2021/7/9

#include<iostream>
#include<queue>
#include<stack>
#include<utility>  // for std::pair
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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        stack<pair<TreeNode*, int> > s;
        s.push(make_pair(root, 1));
        int res = 0;
        while(!s.empty()){
            TreeNode* curNode = s.top().first;
            int depth = s.top().second;
            s.pop();
            if(curNode->left == NULL && curNode->right == NULL)
                res = max(res, depth);
            else{
                if(curNode->left)
                    s.push(make_pair(curNode->left, depth + 1));
                if(curNode->right)
                    s.push(make_pair(curNode->right, depth + 1));
            }
        }
        return res;
    }

    // Note!! Stack is faster than Queue!!!

    /*int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue<pair<TreeNode *, int> >myQue;
        myQue.push(make_pair(root, 1));
        int ans = 1;
        while(!myQue.empty()) {
            TreeNode *curNode = myQue.front().first;
            int dis = myQue.front().second;
            if(curNode->left == NULL && curNode->right == NULL)
                ans = myQue.front().second;
            else {
                if(curNode->left != NULL)
                    myQue.push(make_pair(curNode->left, dis+1));
                if(curNode->right != NULL)
                    myQue.push(make_pair(curNode->right, dis+1));
            }
            myQue.pop();
        }
        return ans;
    }*/

    /*int maxDepth(TreeNode* root) {

        if(root == NULL)
            return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }*/

    // take too much time
    /*int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        else if(root->left == NULL && root->right == NULL)
            return 1;
        else {
            int height = (maxDepth(root->left)>maxDepth(root->right))?maxDepth(root->left):maxDepth(root->right);
            return height+1;
        }
    }*/
};