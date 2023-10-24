/**
 * Source: tinyurl.com/2x42jkzr
 * Date: 2023/10/24
 * Skill:
 * Runtime: 8 ms, faster than 68.56% of C++ online submissions
 * Memory Usage: 22.75 MB, less than 12.77% of C++ online submissions
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
    vector<int> largestValues(TreeNode* root) {
        if (!root)
            return {};
        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            res.push_back(INT32_MIN);
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode * cur = q.front();
                q.pop();
                res.back() = max(res.back(), cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,1,1,1};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}