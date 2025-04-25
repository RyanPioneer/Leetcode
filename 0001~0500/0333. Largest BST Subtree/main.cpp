/**
 * Source: t.ly/FelEr
 * Date: 2025/4/25
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 22.39 MB, less than 42.81% of C++ online submissions
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

typedef tuple<int, int, int> I3;
#define MK make_tuple

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
    int largestBSTSubtree(TreeNode *root) {
        int res = 0;
        function<I3(TreeNode *)> dfs = [&](TreeNode *node) -> I3 {
            if (!node) return MK(0, INT32_MAX, INT32_MIN);
            auto [lnum, lmin, lmax] = dfs(node->left);
            auto [rnum, rmin, rmax] = dfs(node->right);
            int num = 1, mi = node->val, mx = node->val;
            if (lnum >= 0 && lmax < node->val) {
                num += lnum;
                mi = min(lmin, mi);
            } else {
                return MK(-1, 0, 0);
            }
            if (rnum >= 0 && rmin > node->val) {
                num += rnum;
                mx = max(rmax, mx);
            } else {
                return MK(-1, 0, 0);
            }
            res = max(res, num);
            return MK(num, mi, mx);
        };
        dfs(root);
        return res;
    }
};
