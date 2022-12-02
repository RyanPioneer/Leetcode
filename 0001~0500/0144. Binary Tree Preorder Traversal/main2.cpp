/** 
 * Source: https://leetcode.com/problems/binary-tree-preorder-traversal/
 * Date: 2022/11/25
 * Skill: Iterative
 * Runtime: 0 ms, faster than 100.00%
 * Memory Usage:  8.5 MB, less than 41.77%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      The number of nodes in the tree is in the range [0, 100].
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string> 
using namespace std;


// * Definition for a binary tree node.
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> mystack;
        if (root) mystack.push(root);
        while (!mystack.empty()) {
            TreeNode* node = mystack.top();
            mystack.pop();
            res.push_back(node->val);
            if (node->right)mystack.push(node->right);
            if (node->left)mystack.push(node->left);
        }
        return res;
    }
};

int main() {
    Solution s;
    
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();