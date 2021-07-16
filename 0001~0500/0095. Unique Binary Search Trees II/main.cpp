/** 
 * Source: https://leetcode.com/problems/unique-binary-search-trees-ii/
 * Date: 2021/7/16
 * Skill: Recursion
 * Recursion: Trees(n) = Trees(0)*Trees(n-1) + Trees(1)*Trees(n-2) + … + Tress(n-1)*Trees(0)
 * Runtime: 16 ms, faster than 79.00% of C++ online submissions
 * Memory Usage: 16.7 MB, less than 5.80% of C++ online submissions
 * Time complexity: O(3^n)
 * Space complexity: O(3^n)
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
        return generateTrees(1,n);
    }

    vector<TreeNode*> generateTrees(int l, int r) {
        vector<TreeNode*> ans;
        if (l>r) 
            return {NULL};
        for (int index = l; index <= r; index++) {
            for(auto left: generateTrees(l, index-1)) {
                for(auto right: generateTrees(index+1, r)) {
                    ans.push_back(new TreeNode(index));
                    ans.back()->left = left;
                    ans.back()->right = right;
                }
            }
        }
        return ans;
    }


};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();