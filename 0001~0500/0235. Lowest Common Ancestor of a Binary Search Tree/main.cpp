/** 
 * Source: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * Date: 2021/7/19
 * Skill: BST
 * Runtime: 12 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 23.1 MB, less than 90.39% of C++ online submissions 
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *      The number of nodes in the tree is in the range [2, 10^5].
 *      All Node.val are unique.
 *      p != q, p and q will exist in the BST.
 */

#include<iostream>
#include<vector>
using namespace std;

//* Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *low = (p->val < q->val)?p:q;
        TreeNode *high = (low == p)?q:p;
        while (1) {
            if (root->val == p->val || root->val == q->val || (root->val > low->val && root->val < high->val))
                return root;
            if (root->val > high->val)
                root = root->left;
            else
                root = root->right;
        }
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();