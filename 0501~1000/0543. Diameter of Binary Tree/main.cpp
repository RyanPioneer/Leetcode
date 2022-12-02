/** 
 * Source: https://leetcode.com/problems/diameter-of-binary-tree/
 * Date: 2022/11/17
 * Skill: 
 * Runtime: 7 ms, faster than 97.53%
 * Memory Usage: 20.3 MB, less than 64.45%
 * Time complexity: O(n)
 * Space complexity: 
 * Constraints: 
 *      The number of nodes in the tree is in the range [1, 10^4].
 *      -100 <= Node.val <= 100
 */

#include <iostream>
#include <vector>
#include <math.h> 
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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int left_len = diameterOfBinaryTree(root->left);
        int right_len = diameterOfBinaryTree(root->right);
        int left_val, right_val;
        if (root->left) left_val = root->left->val;
        else left_val = 0;
        if (root->right) right_val = root->right->val;
        else right_val = 0;
        root->val = max(left_val, right_val)+1;
        return max(max(left_len, right_len), left_val+right_val);
    }
};

int main() {
    
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();