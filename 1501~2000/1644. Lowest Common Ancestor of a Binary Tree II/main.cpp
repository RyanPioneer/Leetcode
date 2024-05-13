/**
 * Source: ibit.ly/HOAH0
 * Date: 2024/5/13
 * Skill:
 * Ref:
 * Runtime: 183 ms, faster than 5.08% of C++ online submissions
 * Memory Usage: 61.52 MB, less than 15.25% of C++ online submissions
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res;

        function<int(TreeNode *)> dfs = [&](TreeNode *cur) {
            if (!cur) return 0;
            int num = cur->val == p->val || cur->val == q->val ? 1 : 0;
            num += dfs(cur->left);
            num += dfs(cur->right);
            if (num == 2) {
                res = cur;
            }
            return min(num, 1);
        };

        dfs(root);
        return res;
    }
};