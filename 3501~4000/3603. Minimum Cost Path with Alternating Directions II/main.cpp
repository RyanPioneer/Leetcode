/**
 * Source: tinyurl.com/2yxlzenq
 * Date: 2025/7/26
 * Skill:
 * Ref:
 * Runtime: 60 ms, faster than 84.94% of C++ online submissions
 * Memory Usage: 181.55 MB, less than 84.22% of C++ online submissions
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
const int MOD = 1e9 + 7;

class Solution {
   public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<ll>> dp(m, vector<ll>(n, LLONG_MAX));
        waitCost[0][0] = 0;
        dp[0][0] = 1;
        for (ll i = 0; i < m; ++i) {
            for (ll j = 0; j < n; ++j) {
                if (i + 1 < m) {
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + waitCost[i][j] +
                                                         (i + 2) * (j + 1));
                }
                if (j + 1 < n) {
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + waitCost[i][j] +
                                                         (i + 1) * (j + 2));
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
