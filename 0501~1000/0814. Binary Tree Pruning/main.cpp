/** 
 * Source: https://leetcode.com/problems/binary-tree-pruning/
 * Date: 2021/7/23
 * Skill: DFS
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 9.4 MB, less than 86.82% of C++ online submissions
 * Time complexity: O(n), where n is the number of nodes in the tree. We process each node once.
 * Space complexity: O(n), this represents the size of the implicit call stack in our recursion.
 * Constraints: 
 *      The number of nodes in the tree is in the range [1, 200].
 *      Node.val is either 0 or 1.
 */

#include<iostream>
#include<vector>
using namespace std;

//* Definition for a binary tree node.
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
    TreeNode* pruneTree(TreeNode* root) {
        if (root) root->left = pruneTree(root->left), root->right = pruneTree(root->right);
        return (root && (root->left || root->right || root->val)) ? root : NULL;
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();