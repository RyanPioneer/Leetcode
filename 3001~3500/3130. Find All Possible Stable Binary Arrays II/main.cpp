/**
 * Source: tinyurl.com/2chrg8db
 * Date: 2024/4/28
 * Skill:
 * Ref:
 * Runtime: 1403 ms, faster than 66.67% of C++ online submissions
 * Memory Usage: 78.54 MB, less than 83.33% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= zero, one, limit <= 1000
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

typedef long long ll;
const int MOD = 1e9+7, MX = 2e3+10;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int total = zero + one;
        ll dp[MX][MX][2] = {0};

        dp[0][0][0] = dp[0][0][1] = 1;
        dp[1][0][1] = one > 0 ? 1 : 0, dp[1][1][0] = zero > 0 ? 1 : 0;
        for (int i = 2; i <= total; i++) {
            for (int zeroNum = 0; zeroNum <= min(i, zero); zeroNum++) {
                if (zeroNum > 0) { // 0
                    dp[i][zeroNum][0] = (dp[i - 1][zeroNum - 1][0] + dp[i - 1][zeroNum - 1][1]) % MOD;
                    if (zeroNum > limit) {
                        dp[i][zeroNum][0] = (dp[i][zeroNum][0] - dp[i - limit - 1][zeroNum - limit - 1][1] + MOD) % MOD;
                    }
                }
                if (i - zeroNum > 0) { // 1
                    dp[i][zeroNum][1] = (dp[i - 1][zeroNum][0] + dp[i - 1][zeroNum][1]) % MOD;
                    if (i - zeroNum > limit) {
                        dp[i][zeroNum][1] = (dp[i][zeroNum][1] - dp[i - limit - 1][zeroNum][0] + MOD) % MOD;
                    }
                }
            }
        }
        return (dp[total][zero][0] + dp[total][zero][1] + MOD) % MOD;
    }
};