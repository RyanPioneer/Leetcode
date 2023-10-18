/**
 * Source: twtr.to/vmw-S
 * Date: 2023/10/18
 * Skill:
 * Runtime: 284 ms, faster than 76.00% of C++ online submissions
 * Memory Usage: 157.71 MB, less than 78.19% of C++ online submissions
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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> depth[100001], res;
        pairs id2depth[100001];
        function<int(TreeNode*, int)> dfs;
        dfs = [&](TreeNode* node, int cur_depth) {
            int dis = cur_depth;
            if (node->left != nullptr)
                dis = max(dis, dfs(node->left, cur_depth + 1));
            if (node->right != nullptr)
                dis = max(dis, dfs(node->right, cur_depth + 1));
            depth[cur_depth].push_back(dis);
            id2depth[node->val] = {cur_depth, dis};
            return dis;
        };
        dfs(root, 0);
        for (int i = 0; i < 100001; i++) {
            if (depth[i].size() == 0)
                break;
            sort(depth[i].begin(), depth[i].end());
        }
        for (auto q: queries) {
            int d = id2depth[q].first;
            int sz = depth[d].size();
            if (sz == 1)
                res.push_back(d - 1);
            else {
                if (id2depth[q].second != depth[d].back())
                    res.push_back(depth[d].back());
                else
                    res.push_back(depth[d][sz - 2]);
            }
        }
        return res;
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
}