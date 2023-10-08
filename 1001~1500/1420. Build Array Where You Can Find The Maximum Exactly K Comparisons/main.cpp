/**
 * Source: ibit.ly/ScmAg
 * Date: 2023/10/8
 * Skill:
 * Runtime: 3 ms, faster than 98.64% of C++ online submissions
 * Memory Usage: 7.48 MB, less than 65.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
    ll mod = 1e9+7;
public:
    int numOfArrays(int n, int m, int k) {
        ll dp[n][m+1][k+1];
        for (int i=0; i<n; i++)
            for (int j=0; j<=m; j++)
                for (int l=0; l<=k; l++)
                    dp[i][j][l] = 0;
        // vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m + 1, vector<ll>(k + 1, 0)));
        for (int i = 1; i <= m; i++)
            dp[0][i][1] = i;
        for (int i = 1; i < n; i++) {
            dp[i][1][1] = 1;
            for (int j = 2; j <= m; j++) {
                dp[i][j][1] = (dp[i][j - 1][1] + (dp[i - 1][j][1] - dp[i - 1][j - 1][1]) * j % mod) % mod;
                int u = min(i + 1, j);
                for (int t = 2; t <= min(u, k); t++)
                    dp[i][j][t] = (dp[i][j - 1][t] % mod + dp[i - 1][j - 1][t - 1] % mod + (dp[i - 1][j][t] - dp[i - 1][j - 1][t]) * j % mod) % mod;
            }
        }
        return (dp[n - 1][m][k] + mod) % mod;
    }
};


int main() {
    Solution s;
    vector<int> nums{2, 3, 3, 2};
    vector<vector<int>> arr{{1,2}, {2,3}, {2,4}};
}