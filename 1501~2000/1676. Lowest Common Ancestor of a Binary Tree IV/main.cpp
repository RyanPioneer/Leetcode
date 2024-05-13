/**
 * Source: ibit.ly/fUEjM
 * Date: 2024/5/13
 * Skill:
 * Ref:
 * Runtime: 85 ms, faster than 16.48% of C++ online submissions
 * Memory Usage: 45.05 MB, less than 23.08% of C++ online submissions
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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        TreeNode* res = nullptr;
        unordered_set<TreeNode*> st(nodes.begin(), nodes.end());

        function<int(TreeNode*)> dfs = [&](TreeNode* cur) {
            if (!cur) return 0;
            int num = st.find(cur) != end(st) ? 1 : 0;
            num += dfs(cur->left);
            num += dfs(cur->right);
            if (num == st.size() && !res) {
                res = cur;
            }
            return num;
        };

        dfs(root);
        return res;
    }
};