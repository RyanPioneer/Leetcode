/** 
 * Source: https://leetcode.com/problems/unique-binary-search-trees-ii/
 * Reference: https://medium.com/@bill800227/leetcode-95-unique-binary-search-trees-ii-fce58baa1bd8
 * Date: 2021/7/16
 * Skill: DP
 * Runtime: 
 * Memory Usage: 
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
        
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();