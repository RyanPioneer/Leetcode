/**
 * Source: t.ly/zQXaT
 * Date: 2025/4/25
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 33.19 MB, less than 17.83% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int longestConsecutive(TreeNode *root) {
        int res = 1;
        function<int(TreeNode *)> dfs = [&](TreeNode *node) -> int {
            int num = 1;
            if (node->left) {
                int left = dfs(node->left);
                if (node->val + 1 == node->left->val) {
                    num = max(num, left + 1);
                }
            }
            if (node->right) {
                int right = dfs(node->right);
                if (node->val + 1 == node->right->val) {
                    num = max(num, right + 1);
                }
            }
            res = max(res, num);
            return num;
        };
        if (root) {
            dfs(root);
        }
        return res;
    }
};
