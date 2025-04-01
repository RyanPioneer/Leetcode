/**
 * Source: t.ly/5DE7Y
 * Date: 2025/3/9
 * Skill:
 * Ref:
 * Runtime: 45 ms, faster than 50.00% of C++ online submissions
 * Memory Usage: 145.86 MB, less than 65.31% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
#define ll long long

class Solution {
public:
    long long maxCoins(vector<int>& lane1, vector<int>& lane2)
    {
        ll res = max(lane1[0], lane2[0]);
        int n = lane1.size();
        vector<vector<vector<ll>>> dp(
            2, vector<vector<ll>>(2, vector<ll>(3, LLONG_MIN / 2)));
        dp[0][0][0] = lane1[0];
        dp[0][1][1] = lane2[0];

        for (int i = 1; i < n; i++) {
            dp[1][0][0] = max(dp[0][0][0], 0ll) + lane1[i];
            for (int j = 0; j < 2; j++) {
                res = max(res, dp[1][j][0]);
                for (int k = 1; k < 3; k++) {
                    dp[1][j][k] = std::max({ dp[0][j][k], dp[0][1 - j][k - 1], 0LL }) + (j == 0 ? lane1[i] : lane2[i]);
                    res = max(res, dp[1][j][k]);
                }
            }
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[0][j][k] = dp[1][j][k];
                }
            }
        }
        return res;
    }
};
