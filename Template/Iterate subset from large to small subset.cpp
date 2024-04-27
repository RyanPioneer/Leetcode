/**
 * Source: t.ly/6jWzA
 * Date: 2024/4/26
 * Skill:
 * Ref:
 * Runtime: 4 ms, faster than 82.45% of C++ online submissions
 * Memory Usage: 8.34 MB, less than 46.52% of C++ online submissions
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


class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> mp;
        for (auto &t: transactions) {
            mp[t[0]] += t[2];
            mp[t[1]] -= t[2];
        }

        vector<int> nums;
        for (auto &i: mp) nums.push_back(i.second);

        int n = nums.size();
        vector<int> total(1 << n, 0);
        for (int state = 1; state < (1 << n); ++state) {
            for (int j = 0; j < n; ++j) {
                if (((state >> j) & 1)) {
                    total[state] += nums[j];
                }
            }
        }

        vector<int> dp(1 << n, INT32_MAX / 2);
        for (int state = 1; state < (1 << n); state++) {
            if (total[state]) continue;
            dp[state] = __builtin_popcount(state) - 1;
            for (int substate = state; substate > 0; substate = (substate - 1) & state) {
                if (!total[substate]) {
                    dp[state] = min(dp[state], dp[substate] + dp[state - substate]);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};