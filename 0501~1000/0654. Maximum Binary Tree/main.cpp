/** 
 * Source: https://leetcode.com/problems/maximum-binary-tree/
 * Date: 2021/7/22
 * Skill: Divide ans Conquer
 * Runtime: 64 ms, faster than 97.46% of C++ online submissions
 * Memory Usage: 42.7 MB, less than 38.65% of C++ online submissions
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *      1 <= nums.length <= 1000
 *      0 <= nums[i] <= 1000
 *      All integers in nums are unique.
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size()-1);
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        if (left == right) {
            TreeNode *root = new TreeNode(nums[left]);
            return root;
        }
        int mid = left;;
        for (int i = left+1; i <= right; i++) 
            if (nums[mid] < nums[i]) mid = i;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = constructMaximumBinaryTree(nums, left, mid-1);
        root->right = constructMaximumBinaryTree(nums, mid+1, right);
        return root;
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();