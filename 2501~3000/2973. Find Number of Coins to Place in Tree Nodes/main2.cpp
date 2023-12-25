/**
 * Source: is.gd/WowPUT
 * Date: 2023/12/25
 * Skill:
 * Ref:
 * Runtime: 898 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 251.34 MB, less than 100.00% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
const int MX = 20001;


class Solution {
    vector<long long> res;
    vector<int> adj_list[MX];
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = SZ(cost);
        res.resize(n);
        for (auto &e: edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        dfs(0, -1, cost);
        return res;
    }
    vector<int> dfs(int cur, int par, vector<int>& cost) {
        vector<int> nums;
        nums.push_back(cost[cur]);
        for (auto &i: adj_list[cur]) {
            if (i == par) continue;
            vector<int> nums2 = dfs(i, cur, cost);
            for (auto &i: nums2) nums.push_back(i);
        }
        if (nums.size() < 3) res[cur] = 1;
        else {
            sort(begin(nums), end(nums));
            int sz = SZ(nums);
            res[cur] = 0;
            res[cur] = max(res[cur], (ll)nums[sz - 1] * nums[sz - 2] * nums[sz - 3]);
            res[cur] = max(res[cur], (ll)nums[0] * nums[1] * nums[sz - 1]);
            if (sz > 5) {
                vector<int> n = {nums[0], nums[1], nums[sz - 1], nums[sz - 2], nums[sz - 3]};
                nums = n;
            }
        }
        return nums;
    }
};