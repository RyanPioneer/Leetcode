/*
 * @lc app=leetcode id=3638 lang=cpp
 *
 * [3638] 3638. Maximum Balanced Shipments
 */

// @lc code=start

#define ll long long

class Solution {
   public:
    int maxBalancedShipments(vector<int>& weight) {
        int res = 0, n = weight.size();
        weight.insert(weight.begin(), INT_MAX);
        vector<int> dp(n + 1, 0);
        stack<int> inc;
        inc.push(0);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            while (weight[inc.top()] <= weight[i]) {
                inc.pop();
            }
            if (inc.size() > 1) {
                dp[i] = max(dp[i], dp[inc.top() - 1] + 1);
            }
            inc.push(i);
        }
        return dp[n];
    }
};
// @lc code=end
