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
    int index;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        index = postorder.size()-1;
        return buildTree2(inorder, postorder);
    }

    TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0) 
            return NULL;
        if(inorder.size() == 1) {
            TreeNode* curNode = new TreeNode(postorder[index--]);
            return curNode;
        }
        TreeNode* curNode = new TreeNode(postorder[index]);
        int i;
        for(i = 0; i < inorder.size(); i++) {
            if(inorder[i] == postorder[index]) {
                index--;
                break;
            }
        }
        vector<int>leftHalf(inorder.begin(), inorder.begin()+i);
        vector<int>rightHalf(inorder.begin()+i+1, inorder.end());
        curNode->right = buildTree2(rightHalf, postorder);
        curNode->left = buildTree2(leftHalf, postorder);
        return curNode;
    }

};

int main() {
    vector v1{9,3,15,20,7};
    vector v2{9,15,7,20,3};
    Solution s;
    TreeNode* head = s.buildTree(v1, v2);
    cout<<head->val;
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();