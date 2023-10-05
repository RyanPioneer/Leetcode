/**
 * Source: ibit.ly/2eoCE
 * Date: 2023/10/5
 * Skill:
 * Runtime: 145 ms, faster than 71.88% of C++ online submissions
 * Memory Usage: 118.84 MB, less than 34.18% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>


using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int res = 0;
public:
    int maxSumBST(TreeNode* root) {
        is_bst(root);
        return res;
    }
    tuple<int, int, int, bool> is_bst(TreeNode *root) {
        if (root == nullptr)
            return {INT32_MAX, INT32_MIN, 0, true};
        auto [ll, lh, ls, lv] = is_bst(root->left);
        auto [rl, rh, rs, rv] = is_bst(root->right);
        if (lv && rv && root->val > lh && root->val < rl) {
            res = max(res, ls + rs + root->val);
            return {min(ll, root->val), max(rh, root->val), ls + rs + root->val, true};
        } else
            return {0, 0, 0, false};
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}