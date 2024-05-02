/**
 * Source: t.ly/GXh3M
 * Date: 2024/5/1
 * Skill:
 * Ref:
 * Runtime: 120 ms, faster than 48.89% of C++ online submissions
 * Memory Usage: 26.45 MB, less than 28.89% of C++ online submissions
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
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(), k = days[0].size();
        vector<vector<int>> dp(k + 1, vector<int>(n, -1));
        dp[0][0] = 0;
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i - 1][j] > -1) dp[i][j] = dp[i - 1][j] + days[j][i - 1];
                for (int l = 0; l < n; l++) {
                    if (dp[i - 1][l] == -1) continue;
                    if (flights[l][j] == 0) continue;
                    dp[i][j] = max(dp[i][j], dp[i - 1][l] + days[j][i - 1]);
                }
            }
        }
        return *max_element(begin(dp[k]), end(dp[k]));
    }
};