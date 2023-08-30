/**
 * Source: https://rb.gy/k86wg
 * Date: 2023/8/30
 * Skill:
 * Runtime: 8 ms, faster than 92.86% of C++ online submissions
 * Memory Usage: 13.26 MB, less than 38.72% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= steps <= 500
 *      1 <= arrLen <= 10 ** 6
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

#define ll long long
// using ll = long long;

typedef pair<int, int> pairs;

class Solution {
public:
    int numWays(int steps, int arrLen) {
        if (arrLen == 1)
            return 1;
        ll mod = 1e9+7, n = min(steps / 2, arrLen - 1);
        vector<ll> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= steps; i++) {
            vector<ll> dp2 = dp;
            dp[0] = (dp2[0] + dp2[1]) % mod;
            for (int j = 1; j < n; j++)
                dp[j] = (dp2[j - 1] + dp2[j] + dp2[j + 1]) % mod;
            dp[n] = (dp2[n] + dp2[n - 1]) % mod;
        }
        return dp[0];
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    int res = s.numWays(4, 2);
    cout << res << endl;
}