/** 
 * Source: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * Date: 2021/7/11
 * Skill: 
 * Runtime: 
 * Memory Usage: 
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *     
 */

#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive
// Time Complexity: O(n*h) where n is the num of nodes in the tree
// and h is the height of the tree
// Space Complexity: O(h)

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

private:
    TreeNode* buildTree(const vector<int>& preorder, int preorderL, int preorderR,
        const vector<int>& inorder, int inorderL, int inorderR) {

        if(inorderL >= inorderR)
            return NULL;

        if(inorderL + 1 == inorderR)
            return new TreeNode(inorder[inorderL]);

        TreeNode* root = new TreeNode(preorder[preorderL]);
        int rootPos = find(inorder.begin() + inorderL, inorder.begin() + inorderR, root->val) - inorder.begin();
        int lsize = rootPos - inorderL;
        int rsize = inorderR - (rootPos + 1);
        root->left = buildTree(preorder, preorderL + 1, preorderL + 1 + lsize, inorder, inorderL, rootPos);
        root->right = buildTree(preorder, preorderL + 1 + lsize, preorderR, inorder, rootPos + 1, inorderR);
        return root;
    }
};