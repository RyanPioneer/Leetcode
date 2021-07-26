/** 
 * Source: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * Date: 2021/7/26
 * Skill: 
 * Runtime: 4 ms, faster than 99.65% of C++ online submissions
 * Memory Usage: 21.5 MB, less than 42.84% of C++ online submissions
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *     
 *      
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
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if (end <= start) return NULL; 
        int midIdx = start + (end-start)/2;
        TreeNode* root = new TreeNode(nums[midIdx]);
        root->left = sortedArrayToBST(nums, start, midIdx);
        root->right = sortedArrayToBST(nums, midIdx+1, end);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
};


static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();