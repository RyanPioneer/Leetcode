/**
 * Source: t.ly/At2Ah
 * Date: 2024/5/6
 * Skill:
 * Ref:
 * Runtime: 333 ms, faster than 10.00% of C++ online submissions
 * Memory Usage: 17.15 MB, less than 70.00% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= k <= n <= 1000
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
const int MOD = 1e9+7, MX = 1e3+3;


class Solution {
public:
    int waysToDistribute(int n, int k) {
        ll dp[MX][MX];
        fill(dp[0], dp[MX - 1] + MX, -1);

        function<ll(int, int)> helper = [&](int a, int b) {
            if (dp[a][b] != -1) return dp[a][b];
            if (a == 0) return 1ll;
            if (a == k - b) return 1ll;
            dp[a][b] = 0;
            if (b < k) dp[a][b] = (dp[a][b] + helper(a - 1, b + 1) % MOD) % MOD;
            dp[a][b] = (dp[a][b] + helper(a - 1, b) % MOD * b % MOD) % MOD;
            return dp[a][b];
        };

        return helper(n, 0);
    }
};