/** 
 * Source: https://leetcode.com/problems/unique-binary-search-trees-ii/
 * Reference: https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/31516/Share-a-C%2B%2B-DP-solution-with-O(1)-space
 * Date: 2021/7/17
 * Skill: DP
 * * we can construct the result of n node tree just from the result of n-1 node tree.
 * * Here's how we do it: only 2 conditions: 
 * * 1. The nth node is the new root, so newroot->left = oldroot;
 * * 2. the nth node is not root, we traverse the old tree,
 * * every time the node in the old tree has a right child, 
 * * we can perform: old node->right = nth node, nth node ->left = right child; 
 * * and when we reach the end of the tree, don't forget we can also add the nth node here.
 * * One thing to notice is that every time we push a TreeNode in our result, 
 * * I push the clone version of the root, and I recover what I do to the old node immediately. 
 * * This is because you may use the old tree for several times.
 * * 用一個二維的vector(l&r分別代表一個維度)，其element是每一個l&r所形成的tree set(vector<TreeNode*>)
 * Runtime:  8 ms, faster than 99.57% of C++ online submissions 
 * Memory Usage: 12.7 MB, less than 87.24% of C++ online submissions
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *      1 <= n <= 8
 */

#include<iostream>
#include<vector>
#include<string>
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
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> dp(n+1, vector<TreeNode*>());
        dp[0] = {NULL};
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (auto l:dp[j]) {
                    for (auto r:dp[i-j-1]) {
                        TreeNode* root = new TreeNode(j+1);
                        root->left = l;
                        root->right = cloneTreeNode(r, j+1);
                        dp[i].push_back(root);
                    }
                }
            }
        }
        return dp[n];
    }

    TreeNode *cloneTreeNode(TreeNode* root, int offset) {
        if (root == NULL)
            return NULL;
        TreeNode *node = new TreeNode(root->val + offset);
        node->left = cloneTreeNode(root->left, offset);
        node->right = cloneTreeNode(root->right, offset);
        return node;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();