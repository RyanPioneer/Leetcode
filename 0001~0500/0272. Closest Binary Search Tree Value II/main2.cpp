/**
 * Source: t.ly/HT2mI
 * Date: 2024/4/24
 * Skill:
 * Ref:
 * Runtime: 12 ms, faster than 28.40% of C++ online submissions
 * Memory Usage: 19.90 MB, less than 90.27% of C++ online submissions
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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        queue<int> q;

        function<void(TreeNode*)> traverse = [&](TreeNode *node) {
            if (!node) return;
            traverse(node->left);
            if (q.size() < k) {
                q.push(node->val);
                traverse(node->right);
            } else if (abs(q.front() - target) > abs(node->val - target)){
                q.pop();
                q.push(node->val);
                traverse(node->right);
            }
        };

        traverse(root);

        vector<int> res;

        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};