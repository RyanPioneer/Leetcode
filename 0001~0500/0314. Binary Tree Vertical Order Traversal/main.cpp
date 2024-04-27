/**
 * Source: t.ly/W283D
 * Date: 2024/4/26
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 16.80 MB, less than 5.91% of C++ online submissions
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<vector<int>>> mp;

        function<void(TreeNode* , int, int)> dfs = [&](TreeNode* node, int diff, int depth) {
            if (!node) return;
            dfs(node->left, diff - 1, depth + 1);
            mp[diff].push_back({depth, node->val});
            dfs(node->right, diff + 1, depth + 1);
        };

        dfs(root, 0, 0);

        vector<vector<int>> res;

        for (auto &i: mp) {
            vector<vector<int>> &v = i.second;
            sort(begin(v), end(v), [](vector<int> &a, vector<int> &b) {
                return a[0] < b[0];
            });
            vector<int> arr;
            for (auto &i: v) arr.push_back(i[1]);
            res.push_back(arr);
        }
        return res;
    }
};