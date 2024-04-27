/**
 * Source: t.ly/W283D
 * Date: 2024/4/26
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 14.93 MB, less than 29.92% of C++ online submissions
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

typedef pair<int, TreeNode *> PII;


class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        map<int, vector<int>> mp;

        if (!root) return res;
        queue<PII> q;
        q.push({0, root});
        while (!q.empty()) {
            auto [diff, node] = q.front();
            q.pop();
            mp[diff].push_back(node->val);
            if (node->left) q.push({diff - 1, node->left});
            if (node->right) q.push({diff + 1, node->right});
        }

        for (auto &i: mp) {
            res.push_back(i.second);
        }
        return res;
    }
};