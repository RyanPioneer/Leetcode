/**
 * Source: tinyurl.com/ymwsrzr7
 * Date: 2023/10/28
 * Skill:
 * Runtime: 507 ms, faster than 91.59% of C++ online submissions
 * Memory Usage: 426.54 MB, less than 88.32% of C++ online submissions
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
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> num2root;
        int sz = trees.size();
        int merge_num = 0;
        unordered_set<int> leaf_nums;
        for (auto i: trees) {
            if (i->left != nullptr) {
                if (leaf_nums.find(i->left->val) == leaf_nums.end()) {
                    leaf_nums.insert(i->left->val);
                } else {
                    return nullptr;
                }
            }
            if (i->right != nullptr) {
                if (leaf_nums.find(i->right->val) == leaf_nums.end()) {
                    leaf_nums.insert(i->right->val);
                } else {
                    return nullptr;
                }
            }
        }
        TreeNode* root = nullptr;
        for (auto i: trees) {
            num2root[i->val] = i;
            if (leaf_nums.find(i->val) == leaf_nums.end()) {
                if (root == nullptr) root = i;
                else return nullptr;
            }
        }
        if (root == nullptr) return nullptr;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode * cur = q.front();
            q.pop();
            if (cur->left != nullptr && num2root.find(cur->left->val) != num2root.end()) {
                merge_num++;
                cur->left = num2root[cur->left->val];
                q.push(cur->left);
            }
            if (cur->right != nullptr && num2root.find(cur->right->val) != num2root.end()) {
                merge_num++;
                cur->right = num2root[cur->right->val];
                q.push(cur->right);
            }
        }
        if (merge_num != sz - 1) return nullptr;
        int cur_num = INT32_MIN;
        function<bool(TreeNode *)> dfs;
        dfs = [&](TreeNode * cur_node) {
            if (cur_node->left != nullptr && !dfs(cur_node->left)) return false;
            if (cur_num >= cur_node->val) return false;
            cur_num = cur_node->val;
            if (cur_node->right != nullptr && !dfs(cur_node->right)) return false;
            return true;
        };
        if (!dfs(root)) return nullptr;
        return root;
    }
};


int main() {
//    Solution s;
}