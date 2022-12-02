/** 
 * Source: https://leetcode.com/problems/binary-tree-preorder-traversal/
 * Date: 2022/11/25
 * Skill: Recursive
 * Runtime: 3 ms, faster than 63.42%
 * Memory Usage: 8.6 MB, less than 13.47% 
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      The number of nodes in the tree is in the range [0, 100].
 */

#include <iostream>
#include <vector>
#include <utility>
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
        pre(root,res);
        return res;
    }

    void pre(TreeNode* root, vector<int>& res) {
        if (root) {
            res.push_back(root->val);
            pre(root->left,res);
            pre(root->right,res);
        }
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