/**
 * Source: ibit.ly/x4X35
 * Date: 2023/10/15
 * Skill:
 * Runtime: 405 ms, faster than 99.02% of C++ online submissions
 * Memory Usage: 279.09 MB, less than 89.26% of C++ online submissions
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
#include <functional>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;



//  Definition for a binary tree node.
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        int depth_sum[100001] = {0};
        function<void(TreeNode*, int)> dfs;

        dfs = [&](TreeNode* node, int depth) {
            if (node == nullptr)
                return;
            depth_sum[depth] += node->val;
            dfs(node->left, depth + 1);
            dfs(node->right, depth + 1);
        };
        dfs(root, 0);

        function<void(TreeNode*, int)> dfs2;

        dfs2 = [&](TreeNode* node, int depth) {
            if (node == nullptr)
                return;
            int child_sum = 0;
            if (node->left)
                child_sum += node->left->val;
            if (node->right)
                child_sum += node->right->val;
            if (node->left)
                node->left->val = depth_sum[depth + 1] - child_sum;
            if (node->right)
                node->right->val = depth_sum[depth + 1] - child_sum;
            dfs2(node->left, depth + 1);
            dfs2(node->right, depth + 1);
        };
        root->val = 0;
        dfs2(root, 0);
        return root;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
    int c = test(2, 2);
    cout << c << endl;
}