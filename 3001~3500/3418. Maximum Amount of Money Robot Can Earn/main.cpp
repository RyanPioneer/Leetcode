/**
 * Source: ibit.ly/KIKOZ
 * Date: 2025/1/12
 * Skill:
 * Ref:
 * Runtime: 56 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 92.28 MB, less than 60.00% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= m, n <= 500
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


class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        int dp[502][502][3];
        fill(&dp[0][0][0], &dp[0][0][0] + 501 * 501 * 3, INT32_MIN/3);
        dp[1][0][0] = dp[0][1][0] = 0ll;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j][0] = max(dp[i][j-1][0], dp[i-1][j][0]) + coins[i-1][j-1];
                dp[i][j][1] = max(max(dp[i][j-1][1], dp[i-1][j][1]) + coins[i-1][j-1], max(dp[i][j-1][0], dp[i-1][j][0]));
                dp[i][j][2] = max(max(dp[i][j-1][2], dp[i-1][j][2]) + coins[i-1][j-1], max(dp[i][j-1][1], dp[i-1][j][1]));
            }
        }
        return max(dp[m][n][0], max(dp[m][n][1], dp[m][n][2]));
    }
};
