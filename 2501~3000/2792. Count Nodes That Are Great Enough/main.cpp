/**
 * Source: t.ly/gU-pO
 * Date: 2024/5/7
 * Skill:
 * Ref:
 * Runtime: 943 ms, faster than 18.75% of C++ online submissions
 * Memory Usage: 342.24 MB, less than 12.50% of C++ online submissions
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

#define ll long long
const int MX = 1e5+7;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

typedef pair<int, vector<int>> PIM;
#define MK make_pair()


class Solution {
public:
    int countGreatEnoughNodes(TreeNode* root, int k) {
        int res = 0;

        function<PIM(TreeNode* )> dfs = [&](TreeNode* node) {
            vector<int> nums;
            if (!node) return make_pair(0, nums);
            auto [leftNum, leftNums] = dfs(node->left);
            auto [rightNum, rightNums] = dfs(node->right);
            int num = 1 + leftNum + rightNum, pos1 = 0, pos2 = 0;
            int sz1 = leftNums.size(), sz2 = rightNums.size();
            bool used = false;
            while (nums.size() < k && (!used || pos1 < sz1 || pos2 < sz2)) {
                if (!used && (pos1 == sz1 || node->val <= leftNums[pos1]) && (pos2 == sz2 || node->val <= rightNums[pos2])) {
                    nums.push_back(node->val);
                    used = true;
                } else if (pos1 < sz1 && (pos2 == sz2 || leftNums[pos1] <= rightNums[pos2])) {
                    nums.push_back(leftNums[pos1++]);
                } else {
                    nums.push_back(rightNums[pos2++]);
                }
            }
            if (nums.size() == k && nums.back() < node->val) res++;
            return make_pair(num, nums);
        };

        dfs(root);
        return res;
    }
};