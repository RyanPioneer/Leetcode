/** 
 * Source: https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/
 * Date: 2022/11/21
 * Skill: lower_bound(begin(v), end(v), q)
 * Runtime: 505 ms, faster than 77.78%
 * Memory Usage: 134.7 MB, less than 33.33%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      The number of nodes in the tree is in the range [2, 10^5].
 */

#include <iostream>
#include <vector>
#include <unordered_map>
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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> nums;
        vector<vector<int>> res;
        // in case of skewed tree
        preorder_traverse(root, nums);
        for (auto i:queries) {
            res.push_back(find_max_min(i, nums));
        }
        return res;
    }

    void preorder_traverse(TreeNode* root, vector<int>& nums) {
        if (root) {
            if (root->left)
                preorder_traverse(root->left, nums);
            nums.push_back(root->val);
            if (root->right)
                preorder_traverse(root->right, nums);
        }
    }

    vector<int> find_max_min(int q, vector<int>& nums) {
        vector<int> res;
        int left = 0, right = nums.size()-1, min_num, max_num;
        while (left < right) {
            if (nums[(left+right)/2] < q) left = (left+right)/2+1;
            else if (nums[(left+right)/2] == q) return {q,q};
            else right = (left+right)/2;
        }
        if (nums[left] == q) {
            return {q,q};
        } else if (nums[left] > q) {
            if (left == 0) max_num = -1;
            else max_num = nums[left-1];
            min_num = nums[left];
        } else {
            if (right == nums.size()-1) min_num = -1;
            else min_num = nums[left+1];
            max_num = nums[left];
        }
        return {max_num, min_num};
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