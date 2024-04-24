/**
 * Source: t.ly/HT2mI
 * Date: 2024/4/24
 * Skill:
 * Ref:
 * Runtime: 8 ms, faster than 63.81% of C++ online submissions
 * Memory Usage: 20.05 MB, less than 69.65% of C++ online submissions
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

const int MX = 101;


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
        vector<int> nums, res;

        function<void(TreeNode*)> traverse = [&](TreeNode *node) {
            if (!node) return;
            traverse(node->left);
            nums.push_back(node->val);
            traverse(node->right);
        };

        traverse(root);

        auto it1 = upper_bound(begin(nums), end(nums), target);
        if (it1 == begin(nums)) return vector<int>({nums.begin(), nums.begin() + k});
        if (it1 == end(nums)) return vector<int>({nums.end() - k, nums.end()});
        auto it2 = prev(it1);
        while (k--) {
            if (it1 == end(nums) || (it2 != prev(begin(nums)) && *it1 -target > target - *it2)) {
                res.push_back(*it2);
                it2 = prev(it2);
            } else {
                res.push_back(*it1);
                it1 = next(it1);
            }
        }
        return res;
    }
};