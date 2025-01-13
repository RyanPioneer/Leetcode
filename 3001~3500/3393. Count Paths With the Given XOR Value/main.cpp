/**
 * Source: ibit.ly/Ra1wp
 * Date: 2025/1/13
 * Skill:
 * Ref:
 * Runtime: 187 ms, faster than 70.18% of C++ online submissions
 * Memory Usage: 52.92 MB, less than 83.38% of C++ online submissions
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
const int MOD = 1e9+7;


class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        ll dp[310][310][16] = {0};
        dp[1][0][0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int num = 0; num < 16; num++) {
                    dp[i][j][num] = (dp[i-1][j][num ^ grid[i-1][j-1]] + dp[i][j-1][num ^ grid[i-1][j-1]]) % MOD;
                }
            }
        }
        return dp[m][n][k];
    }
};
