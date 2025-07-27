/**
 * Source: tinyurl.com/2xlynq7h
 * Date: 2025/4/20
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 18.63 MB, less than 45.76% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      -1000 <= Node.val <= 1000
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
#define ull unsigned long long

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
    int countUnivalSubtrees(TreeNode *root) {
        int res = 0;
        function<int(TreeNode *)> dfs = [&](TreeNode *node) {
            bool equal = true;
            if (node->left) {
                int left = dfs(node->left);
                if (left != node->val) {
                    equal = false;
                }
            }
            if (node->right) {
                int right = dfs(node->right);
                if (right != node->val) {
                    equal = false;
                }
            }
            if (equal) {
                ++res;
                return node->val;
            }
            return -1001;
        };
        if (root) {
            dfs(root);
        }
        return res;
    }
};
