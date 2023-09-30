/**
 * Source: ibit.ly/CBxSQ
 * Date: 2023/9/30
 * Skill:
 * Runtime: 30 ms, faster than 7.22% of C++ online submissions
 * Memory Usage: 26.97 MB, less than 15.02% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      The number of nodes in the tree is in the range [1, 1000].
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>

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

typedef pair<TreeNode *, bool> pairs;

class Solution {
    map<pairs, int> dp;
public:
    int minCameraCover(TreeNode* root) {
        return dfs(root, false);
    }
    int dfs(TreeNode* node, bool par_has_cam) {
        if (node == nullptr)
            return 0;
        if (dp.find({node, par_has_cam}) != dp.end())
            return dp[{node, par_has_cam}];
        int res = 1 + dfs(node->left, true) + dfs(node->right, true);
        if (par_has_cam) {
            res = min(res, dfs(node->left, false) + dfs(node->right, false));
        } else {
            if (node->left)
                res = min(res, 1 + dfs(node->left->left, true) +
                               dfs(node->left->right, true) + dfs(node->right, false));
            if (node->right)
                res = min(res, 1 + dfs(node->right->left, true) +
                               dfs(node->right->right, true) + dfs(node->left, false));
        }
        dp[{node, par_has_cam}] = res;
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}