/**
 * Source: tinyurl.com/yjaqjjyc
 * Date: 2025/4/8
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 11.61 MB, less than 31.36% of C++ online submissions
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
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root)
    {
        vector<vector<int>> res;

        function<int(TreeNode*)> dfs = [&](TreeNode* cur) {
            if (!cur) {
                return 0;
            }
            int d = 0;
            d = max(d, dfs(cur->left));
            d = max(d, dfs(cur->right));
            if (d == res.size()) {
                res.push_back({});
            }
            res[d].push_back(cur->val);
            return d + 1;
        };
        dfs(root);
        return res;
    }
};
