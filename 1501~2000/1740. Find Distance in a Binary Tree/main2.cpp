/**
 * Source: t.ly/g4M9e
 * Date: 2024/5/11
 * Skill:
 * Ref:
 * Runtime: 71 ms, faster than 5.14% of C++ online submissions
 * Memory Usage: 30.76 MB, less than 20.89% of C++ online submissions
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
public:
    int findDistance(TreeNode* root, int p, int q) {
        if (p == q) return 0;
        int res = INT32_MAX;

        function<int(TreeNode*)> dfs = [&](TreeNode* cur) {
            if (!cur) return -1;
            int l = dfs(cur->left);
            int r = dfs(cur->right);
            if (l == -1 && r == -1) {
                if (cur->val == p || cur->val == q) {
                    return 0;
                } else {
                    return -1;
                }
            } else if (l != -1 && r != -1) {
                res = l + r + 2;
                return -1;
            } else if (l != -1) {
                if (cur->val == p || cur->val == q) {
                    res = l + 1;
                    return -1;
                } else {
                    return l + 1;
                }
            } else {
                if (cur->val == p || cur->val == q) {
                    res = r + 1;
                    return -1;
                } else {
                    return r + 1;
                }
            }
        };

        dfs(root);
        return res;
    }
};