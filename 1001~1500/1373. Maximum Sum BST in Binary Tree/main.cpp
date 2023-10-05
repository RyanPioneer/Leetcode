/**
 * Source: ibit.ly/2eoCE
 * Date: 2023/10/5
 * Skill:
 * Runtime: 329 ms, faster than 16.39% of C++ online submissions
 * Memory Usage: 198.13 MB, less than 16.79% of C++ online submissions
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
    unordered_map<TreeNode*, int>node2sum, node2max, node2min;
    int res = 0;
public:
    int maxSumBST(TreeNode* root) {
        is_bst(root);
        return res;
    }
    bool is_bst(TreeNode *root) {
        bool l = true, r = true;
        int total = root->val;
        if (root->left != nullptr)
            l = is_bst(root->left);
        if (root->right != nullptr)
            r = is_bst(root->right);
        if (not l or not r)
            return false;
        if (root->left != nullptr) {
            if (node2max[root->left] >= root->val)
                return false;
            else {
                total += node2sum[root->left];
                node2min[root] = node2min[root->left];
            }
        } else
            node2min[root] = root->val;
        if (root->right != nullptr) {
            if (node2min[root->right] <= root->val)
                return false;
            else {
                total += node2sum[root->right];
                node2max[root] = node2max[root->right];
            }
        } else
            node2max[root] = root->val;

        res = max(res, total);
        node2sum[root] = total;
        return true;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}