/**
 * Source: is.gd/WowPUT
 * Date: 2023/12/24
 * Skill:
 * Ref:
 * Runtime: 1206 ms, faster than 44.44% of C++ online submissions
 * Memory Usage: 365.37 MB, less than 44.44% of C++ online submissions
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
    multiset<int> dfs(int cur, int par, vector<int>& cost) {
        multiset<int> nums;
        nums.insert(cost[cur]);
        for (auto &i: adj_list[cur]) {
            if (i == par) continue;
            multiset<int> nums2 = dfs(i, cur, cost);
            for (auto &i: nums2) nums.insert(i);
        }
        if (nums.size() < 3) res[cur] = 1;
        else {
            res[cur] = 0;
            res[cur] = max(res[cur], (ll)*rbegin(nums) * *next(rbegin(nums)) * *next(next(rbegin(nums))));
            res[cur] = max(res[cur], (ll)*rbegin(nums) * *begin(nums) * *next(begin(nums)));
            int sz = SZ(nums);
            if (sz > 5) {
                vector<int> n = {*rbegin(nums), *next(rbegin(nums)), *next(next(rbegin(nums))), *begin(nums), *next(begin(nums))};
                nums.clear();
                nums.insert(begin(n), end(n));
            }
        }
        return nums;
    }
};