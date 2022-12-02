/**
 * Source: https://leetcode.com/problems/paint-house-iii/
 * Date: 2022/7/9
 * Skill:
 * Runtime:
 * Memory Usage:
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<int> houses, vector<vector<int>> cost, int m, int n, int target) {
        /**
         * Define dp[i][j][k] as the minimum cost where we have k neighborhoods
         * in the first i houses and the i-th house is painted with the color j.
         *
         */
        vector<vector<vector<int>>> dp(m);
        for (int i = 0; i < m; i++) {
            dp[i].resize(n);
            for (int j = 0; j < n; j++) {
                dp[i][j].resize(target);
            }
        }
        for (int j = 0; j < n; j++) {
            if (houses[0] == 0)
                dp[0][j][0] = cost[0][j];
            else if (houses[0]-1 == j)
                dp[0][j][0] = 0;
            else
                dp[0][j][0] = -1;
            for (int k = 1; k < target; k++)
                dp[0][j][k] = -1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i-1][j][0] != -1) {
                    if (houses[i] == 0)
                        dp[i][j][0] = cost[i][j] + dp[i-1][j][0];
                    else if (houses[i]-1 == j)
                        dp[i][j][0] = dp[i-1][j][0];
                    else
                        dp[i][j][0] = -1;
                } else
                    dp[i][j][0] = -1;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 1; k < target; k++) {
                    if (houses[i] == 0 || houses[i]-1 == j) {
                        int minimum = INT_MAX;
                        for (int l = 0; l < n; l++) {
                            if (l != j && dp[i-1][l][k-1] != -1)
                                minimum = min(minimum, dp[i-1][l][k-1]);
                            else if (l == j && dp[i-1][l][k] != -1)
                                minimum = min(minimum, dp[i-1][l][k]);
                        }
                        if (minimum != INT_MAX) {
                            if (houses[i] == 0)
                                dp[i][j][k] = minimum+cost[i][j];
                            else
                                dp[i][j][k] = minimum;
                        } else
                            dp[i][j][k] = -1;
                    } else
                        dp[i][j][k] = -1;
                }
            }
        }
        int minimum = INT_MAX;
        for (int i = 0; i < n; i++)
            if (dp[m-1][i][target-1] != -1)
                minimum = min(minimum, dp[m-1][i][target-1]);
        if (minimum == INT_MAX)
            return -1;
        else
            return minimum;

    }
};

int main() {
    Solution s;
    cout << s.minCost({3,1,2,3}, {{1,1,1},{1,1,1},{1,1,1},{1,1,1}}, 4, 3, 3);
    
}

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
