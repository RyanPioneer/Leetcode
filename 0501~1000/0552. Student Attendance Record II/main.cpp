/**
 * Source: is.gd/vQEoKw
 * Date: 2023/12/5
 * Skill:
 * Ref:
 * Runtime: 23 ms, faster than 96.01% of C++ online submissions
 * Memory Usage: 6.22 MB, less than 99.11% of C++ online submissions
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
ll mod = 1e9+7;
const int MX = 1e5;


class Solution {
public:
    int checkRecord(int n) {
        if (n == 1) return 3;
        if (n == 2) return 8;
        ll dp[2][3] = {0}, dp2[2][3], res = 0;    // A: 0, L: 1, P: 2
        dp[0][0] = 2, dp[0][1] = 1, dp[0][2] = 1;
        dp[1][0] = 3, dp[1][1] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 3; k++) {
                    dp2[j][k] = dp[j][k];
                    dp[j][k] = 0;
                }
            }
            dp[0][0] = (dp2[0][0] + dp2[0][1] + dp2[0][2]) % mod;
            dp[0][1] = dp2[0][0] % mod;
            dp[0][2] = dp2[0][1] % mod;
            dp[1][0] = (dp2[0][0] + dp2[0][1] + dp2[0][2] + dp2[1][0] + dp2[1][1] + dp2[1][2]) % mod;
            dp[1][1] = dp2[1][0] % mod;
            dp[1][2] = dp2[1][1] % mod;
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                res = (res + dp[i][j]) % mod;
            }
        }
        return res;
    }
};