/**
 * Source: jpeg.ly/9v3MB
 * Date: 2025/1/19
 * Skill:
 * Ref:
 * Runtime: 41 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 184.01 MB, less than 100.00% of C++ online submissions
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
const int MX = 1e5+10;


class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(3, vector<ll>(3, LLONG_MAX/4)));

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                dp[0][i][j] = cost[0][i] + cost[n-1][j];
            }
        }
        
        for (int i = 1; i < n/2; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (j == k) continue;
                    ll mi = LLONG_MAX / 4;
                    for (int l = 0; l < 3; l++) {
                        for (int m = 0; m < 3; m++) {
                            if (l == m) continue;
                            if (j == l || k == m) continue;
                            mi = min(mi, dp[0][l][m]);
                        }
                    }
                    dp[1][j][k] = mi + cost[i][j] + cost[n-1-i][k];
                }
            }
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[0][j][k] = j == k ? LLONG_MAX/4 : dp[1][j][k];
                }
            }
        }
        
        ll res = LLONG_MAX / 4;
        for (const auto& row : dp[0]) {
            res = min(res, *min_element(row.begin(), row.end()));
        }
        return res;
    }
};
