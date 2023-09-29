/**
 * Source: ibit.ly/2vSsw
 * Date: 2023/9/29
 * Skill:
 * Runtime: 569 ms, faster than 56.05% of C++ online submissions
 * Memory Usage: 191.47 MB, less than 42.04% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= nums[i] <= 50
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
    vector<int> num2depth;
    stack<int> num2idx[51];
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        num2depth.resize(nums.size());
        vector<vector<int>> adj_list(nums.size());
        for (auto e: edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        vector<int> res(nums.size(), -1);
        dfs(0, -1, 0, adj_list, res, nums);
        return res;
    }
    void dfs(int cur, int par, int depth, vector<vector<int>>& adj_list, vector<int>& res, vector<int>& nums) {
        int ancestor = -1, max_depth = -1, cur_num = nums[cur];
        for (int i = 1; i <= 50; i++) {
            if (!num2idx[i].empty() && gcd(cur_num, i) == 1 && max_depth < num2depth[num2idx[i].top()]) {
                max_depth = num2depth[num2idx[i].top()];
                ancestor = num2idx[i].top();
            }
        }
        res[cur] = ancestor;
        num2idx[cur_num].push(cur);
        num2depth[cur] = depth;
        for (auto i: adj_list[cur])
            if (i != par)
                dfs(i, cur, depth + 1, adj_list, res, nums);
        num2idx[cur_num].pop();
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
    vector<int> res = s.getCoprimes(nums, arr1);
}