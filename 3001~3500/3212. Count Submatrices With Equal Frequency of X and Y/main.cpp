/**
 * Source: jpeg.ly/CRJL_
 * Date: 2025/1/19
 * Skill:
 * Ref:
 * Runtime: 33 ms, faster than 89.77% of C++ online submissions
 * Memory Usage: 129.66 MB, less than 60.23% of C++ online submissions
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
const int MX = 1e3+1;


class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<array<int, 2>>> dp(m + 1, vector<array<int, 2>>(n + 1));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j][0] = dp[i-1][j][0] + dp[i][j-1][0] - dp[i-1][j-1][0] + (grid[i-1][j-1] == 'X');
                dp[i][j][1] = dp[i-1][j][1] + dp[i][j-1][1] - dp[i-1][j-1][1] + (grid[i-1][j-1] == 'Y');
                if (dp[i][j][0] == dp[i][j][1] && dp[i][j][0] > 0) {
                    res++;
                }
            }
        }
        return res;
    }
};
