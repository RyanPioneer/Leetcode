/**
 * Source: t.ly/g4M9e
 * Date: 2024/5/11
 * Skill:
 * Ref:
 * Runtime: 101 ms, faster than 5.14% of C++ online submissions
 * Memory Usage: 39.78 MB, less than 8.22% of C++ online submissions
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
        unordered_map<int, int> num2depth;
        num2depth[-1] = 0;

        function<void(TreeNode*, int)> dfs = [&](TreeNode* cur, int f) {
            if (!cur) return;
            num2depth[cur->val] = num2depth[f] + 1;
            dfs(cur->left, cur->val);
            dfs(cur->right, cur->val);
        };

        function<TreeNode*(TreeNode*)> lowestCommonAncestor = [&](TreeNode* cur) {
            TreeNode* t = nullptr;
            if (!cur) return t;
            if (cur->val == p || cur->val == q) return cur;
            TreeNode *l = lowestCommonAncestor(cur->left);
            TreeNode *r = lowestCommonAncestor(cur->right);
            if (l && r) return cur;
            if (l) return l;
            if (r) return r;
            return t;
        };

        dfs(root, -1);
        TreeNode* lca = lowestCommonAncestor(root);
        return num2depth[p] + num2depth[q] - 2 * num2depth[lca->val];
    }
};