/**
 * Source: t.ly/vxcey
 * Date: 2024/5/19
 * Skill:
 * Ref:
 * Runtime: 4 ms, faster than 91.43% of C++ online submissions
 * Memory Usage: 21.16 MB, less than 62.86% of C++ online submissions
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
typedef pair<int, int> pii;

#define MK make_pair
#define SZ(X) ((int)(X).size())
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)


const int MX = 1e5+10;


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
    int longestConsecutive(TreeNode* root) {
        int res = 1;

        function<pii(TreeNode* cur)> dfs = [&](TreeNode *node) {
            if (!node) return MK(0, 0);
            pii p(1, 1);
            pii l = dfs(node->left);
            pii r = dfs(node->right);
            int ll = 1, rr = 1;
            if (node->left) {
                if (node->left->val == node->val - 1) {
                    ll += l.first;
                    p.first = max(p.first, l.first + 1);
                } else if (node->left->val == node->val + 1) {
                    rr += l.second;
                    p.second = max(p.second, l.second + 1);
                }
            }
            if (node->right) {
                if (node->right->val == node->val + 1) {
                    ll += r.second;
                    p.second = max(p.second, r.second + 1);
                } else if (node->right->val == node->val - 1) {
                    rr += r.first;
                    p.first = max(p.first, r.first + 1);
                }
            }
            res = max({res, ll, rr});
            return p;
        };

        dfs(root);
        return res;
    }
};