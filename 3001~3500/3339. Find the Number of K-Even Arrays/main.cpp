/**
 * Source: ibit.ly/95Yuq
 * Date: 2024/12/31
 * Skill:
 * Ref:
 * Runtime: 15 ms, faster than 81.25% of C++ online submissions
 * Memory Usage: 9.50 MB, less than 70.31% of C++ online submissions
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
const int MOD = 1e9 + 7, MX = 750;

class Solution {
public:
    int countOfArrays(int n, int m, int k) {
        ll dp[2][2][MX] = {0};
        ll oddCnt = m / 2 + m % 2, evenCnt = m / 2;
        dp[0][0][0] = evenCnt;
        dp[0][1][0] = oddCnt;
        for (int i = 1; i < n; i++) {
            dp[1][1][0] = oddCnt * (dp[0][1][0] + dp[0][0][0]) % MOD;
            dp[1][0][0] = evenCnt * dp[0][1][0] % MOD;
            for (int j = 1; j <= k; j++) {
                dp[1][1][j] = oddCnt * (dp[0][1][j] + dp[0][0][j]) % MOD;
                dp[1][0][j] = evenCnt * (dp[0][0][j-1] + dp[0][1][j]) % MOD;
            }
            for (int j = 0; j <= k; j++) {
                for (int l = 0; l < 2; l++) {
                    dp[0][l][j] = dp[1][l][j];
                }
            }
        }
        return (dp[0][0][k] + dp[0][1][k]) % MOD;
    }
};
