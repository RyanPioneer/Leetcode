/*
 * @lc app=leetcode id=3610 lang=cpp
 *
 * [3610] Minimum Number of Primes to Sum to Target
 */

// @lc code=start
#define ll long long
const int MX = 1001;
class Solution {
    void better(int &x, int y) {
        if (x < 0 || x > y) {
            x = y;
        }
    }

   public:
    int minNumberOfPrimes(int n, int m) {
        vector<bool> mark(n + 1);
        vector<int> dp(n + 1, -1);
        mark[0] = mark[1] = true;
        dp[0] = 0;
        for (int i = 2; m && i <= n; ++i) {
            if (mark[i]) continue;
            for (int j = i + i; j <= n; j += i) {
                mark[j] = true;
            }
            --m;
            for (int j = i; j <= n; ++j) {
                if (dp[j - i] >= 0) {
                    better(dp[j], dp[j - i] + 1);
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end
