/*
 * @lc app=leetcode id=3647 lang=cpp
 *
 * [3647] Maximum Weight in Two Bags
 */

// @lc code=start

#define ll long long
const int MX = 310;

class Solution {
   public:
    int maxWeight(vector<int>& weights, int w1, int w2) {
        int dp[MX][MX] = {0}, res = 0;
        dp[0][0] = 1;
        for (auto w : weights) {
            for (int i = w1; i >= 0; i--) {
                for (int j = w2; j >= 0; j--) {
                    if (i >= w && dp[i - w][j]) {
                        dp[i][j] = 1;
                        res = max(res, i + j);
                    }
                    if (j >= w && dp[i][j - w]) {
                        dp[i][j] = 1;
                        res = max(res, i + j);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
