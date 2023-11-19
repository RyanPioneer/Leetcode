/**
 * Source: twtr.to/vhGdU
 * Date: 2023/11/19
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 11.08 MB, less than 42.41% of C++ online submissions
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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->val == x) {
                int left = (cur->left == nullptr ? 0 : dfs(cur->left));
                int right = (cur->right == nullptr ? 0 : dfs(cur->right));
                int up = n - left - right - 1;
                if (up * 2 > n || left * 2 > n || right * 2 > n) return true;
                else return false;
            }
            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }
        return false;
    }
    int dfs(TreeNode * cur) {
        int num = 1;
        num += (cur->left == nullptr ? 0 : dfs(cur->left));
        num += (cur->right == nullptr ? 0 : dfs(cur->right));
        return num;
    }
};