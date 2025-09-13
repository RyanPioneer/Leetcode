/*
 * @lc app=leetcode id=3652 lang=cpp
 *
 * [3652] Best Time to Buy and Sell Stock using Strategy
 */

// @lc code=start
#define ll long long
class Solution {
   public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        ll total = 0;
        for (int i = 0; i < prices.size(); i++) {
            total += prices[i] * strategy[i];
        }
        ll ori = 0, cur = 0, res = total;
        for (int i = 0; i < k; i++) {
            ori += prices[i] * strategy[i];
            if (i >= k / 2) {
                cur += prices[i];
            }
        }
        res = max(res, total - ori + cur);
        for (int i = k; i < prices.size(); i++) {
            ori -= prices[i - k] * strategy[i - k];
            ori += prices[i] * strategy[i];
            cur += prices[i] - prices[i - k / 2];
            res = max(res, total - ori + cur);
        }
        return res;
    }
};
// @lc code=end
