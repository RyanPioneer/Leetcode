/** 
 * Source: https://leetcode.com/problems/out-of-boundary-paths/
 * Date: 2022/7/18
 * Skill: 
 * Runtime: 47 ms, faster than 16.57%
 * Memory Usage: 6.8 MB, less than 68.05%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= m, n <= 50
 *      0 <= maxMove <= 50
 */

#include <iostream>
#include <vector> 
#include <utility>
#include <algorithm>
//#include <bits/stdc++.h>

#define MOD 1000000007
#define LLI long long int 

using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (!maxMove)
            return 0;
        vector<vector<vector<LLI>>>dp(2);
        vector<pair<LLI,LLI>> dir = {make_pair(-1,0), make_pair(1,0), make_pair(0,-1), make_pair(0,1)};
        LLI ans = 0;
        for (int i = 0; i < 2; i++) {
            dp[i].resize(m);
            for (int j = 0; j < m; j++) {
                dp[i][j].resize(n,0);
            }
        }
        dp[0][startRow][startColumn] = 1;
        for (int i = 1; i < maxMove; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    for (auto l : dir) 
                        if (isLegal(j+l.first, k+l.second, m, n)) 
                            dp[1][j+l.first][k+l.second] = (dp[0][j][k]+dp[1][j+l.first][k+l.second])%MOD;
                    ans = (ans+findNum(j,k,m,n)*dp[0][j][k])%MOD;
                }
            }
            dp[0] = dp[1];
            for (int j = 0; j < m; j++)
                fill(dp[1][j].begin(), dp[1][j].end(), 0);
        }
        for (int j = 0; j < m; j++) 
            for (int k = 0; k < n; k++) 
                ans = (ans+findNum(j,k,m,n)*dp[0][j][k])%MOD;
        return ans;
    }

    bool isLegal(int x, int y, int m, int n) {
        if (x >= 0 && x < m && y >= 0 && y < n)
            return true;
        else
            return false;
    }

    int findNum(int x, int y, int m, int n) {
        int num = 0;
        if (x == 0)
            num++;
        if (x == m-1)
            num++;
        if (y == 0)
            num++;
        if (y == n-1)
            num++;
        return num;
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();