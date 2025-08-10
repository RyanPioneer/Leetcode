/*
 * @lc app=leetcode id=3573 lang=cpp
 *
 * [3573] Best Time to Buy and Sell Stock V
 */

// @lc code=start
const int MX = 1e3 + 10;
class Solution {
   public:
    long long maximumProfit(vector<int>& prices, int k) {
        prices.insert(prices.begin(), 0);
        using ll = long long;
        ll dp[MX][MX] = {0};
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = max(
                    dp[i - 1][j],
                    (i > 0 ? prices[i] - prices[i - 1] + dp[i - 1][j - 1] : 0));
            }
        }
        return dp[prices.size() - 1][k];
    }
};
// @lc code=end
