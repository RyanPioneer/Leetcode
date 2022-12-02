/** 
 * Source: https://leetcode.com/problems/count-complete-tree-nodes/
 * Date: 2022/11/15
 * Skill: 
 * Runtime: 29 ms, faster than 97.73% 
 * Memory Usage: 30.7 MB, less than 93.85%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      The number of nodes in the tree is in the range [0, 5 * 10^4].
 *      0 <= Node.val <= 5 * 10^4
 *  * The tree is guaranteed to be complete.
 *  * Design an algorithm that runs in less than O(n) time complexity.
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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int left_length = 0, right_length = 0;
        TreeNode *left = root, *right = root;
        while (left) {
            left = left->left;
            left_length++;
        }
        while (right) {
            right = right->right;
            right_length++;
        }
        if (left_length == right_length)
            return pow(2, left_length)-1;
        return countNodes(root->left)+countNodes(root->right)+1;
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