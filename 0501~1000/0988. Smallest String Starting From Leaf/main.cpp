/**
 * Source: is.gd/YDcHOl
 * Date: 2024/4/17
 * Skill:
 * Ref:
 * Runtime: 9 ms, faster than 53.79% of C++ online submissions
 * Memory Usage: 20.24 MB, less than 78.11% of C++ online submissions
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
    string smallestFromLeaf(TreeNode* root) {
        string res, cur;

        function<void(TreeNode*)> dfs = [&](TreeNode *node) {
            cur = char('a' + node->val) + cur;
            if (node->left) dfs(node->left);
            if (node->right) dfs(node->right);
            if (!node->left && !node->right) {
                if (res.empty() || res > cur) {
                    res = cur;
                }
            }
            cur.erase(0, 1);
        };

        dfs(root);
        return res;
    }
};