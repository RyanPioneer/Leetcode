/**
 * Source: t.ly/Gw6yG
 * Date: 2024/5/26
 * Skill:
 * Ref:
 * Runtime: 182 ms, faster than 90.00% of C++ online submissions
 * Memory Usage: 146.56 MB, less than 62.50% of C++ online submissions
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

#define ll long long
const int MX = 1e5+7;


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
    int minimumLevel(TreeNode* root) {
        int res = -1, mi = INT32_MAX, depth = 0;
        queue<TreeNode *> q;

        q.push(root);
        while (!q.empty()) {
            depth++;
            ll total = 0;
            int sz = q.size();
            while (sz--) {
                TreeNode *node = q.front();
                q.pop();
                total += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (total < mi) {
                mi = total;
                res = depth;
            }
        }
        return res;
    }
};