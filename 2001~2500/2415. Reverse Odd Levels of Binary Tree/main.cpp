/**
 * Source: tinyurl.com/ylmurm3u
 * Date: 2023/10/20
 * Skill:
 * Runtime: 155 ms, faster than 91.54% of C++ online submissions
 * Memory Usage: 75.40 MB, less than 59.86% of C++ online submissions
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        deque<TreeNode*> q;
        int depth = -1;
        q.push_back(root);
        vector<int> nums;
        while (!q.empty()) {
            depth = (depth + 1) % 2;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop_front();
                if (node->left == nullptr)
                    continue;
                if (depth == 0) {
                    nums.push_back(node->left->val);
                    nums.push_back(node->right->val);
                    q.push_back(node);
                } else {
                    q.push_back(node->left);
                    q.push_back(node->right);
                }
            }
            if (depth == 0) {
                int sz2 = q.size();
                for (int i = 0; i < sz2; i++) {
                    TreeNode* node = q.front();
                    q.pop_front();
                    node->left->val = nums.back();
                    nums.pop_back();
                    q.push_back(node->left);
                    node->right->val = nums.back();
                    nums.pop_back();
                    q.push_back(node->right);
                }
            }
        }
        return root;
    }
};


int main() {
    Solution s;
    vector<int> nums{5,4,6};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}