/**
 * Source: twtr.to/Utrjs
 * Date: 2023/11/22
 * Skill:
 * Ref:
 * Runtime: 27 ms, faster than 89.11% of C++ online submissions
 * Memory Usage: 33.28 MB, less than 85.35% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    int limit;
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (root->left == nullptr && root->right == nullptr) {
            return root->val < limit ? nullptr : root;
        }
        this->limit = limit;
        dfs(root, 0);
        return root->left != nullptr || root->right != nullptr ? root : nullptr;
    }
    int dfs(TreeNode* node, int presum) {
        int mx = INT32_MIN, val = node->val;
        if (node->left) {
            int num = dfs(node->left, presum + val);
            mx = max(mx, num);
            if (num + presum + val < limit) node->left = nullptr;
        }
        if (node->right) {
            int num = dfs(node->right, presum + val);
            mx = max(mx, num);
            if (num + presum + val < limit) node->right = nullptr;
        }
        return (mx == INT32_MIN ? 0 : mx) + val;
    }
};