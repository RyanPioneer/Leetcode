/**
 * Source: t.ly/qlm-F
 * Date: 2023/10/14
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 11.24 MB, less than 42.92% of C++ online submissions
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
    bool isCousins(TreeNode* root, int x, int y) {
        int depth[101], parent[101];
        function<void(TreeNode*, TreeNode*, int)> dfs;

        dfs = [&](TreeNode* cur, TreeNode* par, int cur_depth) {
            if (cur == nullptr)
                return;
            if (par == nullptr)
                parent[cur->val] = -1;
            else
                parent[cur->val] = par->val;
            depth[cur->val] = cur_depth;
            dfs(cur->left, cur, cur_depth + 1);
            dfs(cur->right, cur, cur_depth + 1);
        };
        dfs(root, nullptr, 0);
        return depth[x] == depth[y] && parent[x] != parent[y];
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int,int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
    int c = test(2, 2);
    cout << c << endl;
}