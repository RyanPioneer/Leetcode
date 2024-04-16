/**
 * Source: is.gd/eO7P7K
 * Date: 2024/4/16
 * Skill:
 * Ref:
 * Runtime: 13 ms, faster than 56.48% of C++ online submissions
 * Memory Usage: 24.24 MB, less than 74.48% of C++ online submissions
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val, root, nullptr);
            return newRoot;
        }

        function<void(TreeNode*, int)> dfs = [&](TreeNode* cur, int d) {
            if (cur == nullptr) return;
            if (d == depth - 1) {
                cur->left = new TreeNode(val, cur->left, nullptr);
                cur->right = new TreeNode(val, nullptr, cur->right);
                return;
            }
            dfs(cur->left, d + 1);
            dfs(cur->right, d + 1);
        };

        dfs(root, 1);
        return root;
    }
};