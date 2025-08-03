/*
 * @lc app=leetcode id=3578 lang=cpp
 *
 * [3578] Count Partitions With Max-Min Difference at Most K
 */

// @lc code=start
#define ll long long
const int MOD = 1e9 + 7;
class Solution {
   public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<int> dp(n + 1, 1), presum(n + 1, 1);
        deque<int> inc, dec;

        for (int i = 1, left = 1; i <= n; i++) {
            while (!inc.empty() && nums[inc.back()] > nums[i]) {
                inc.pop_back();
            }
            inc.push_back(i);
            while (!dec.empty() && nums[dec.back()] < nums[i]) {
                dec.pop_back();
            }
            dec.push_back(i);

            while (nums[dec.front()] - nums[inc.front()] > k) {
                if (left == inc.front()) {
                    inc.pop_front();
                }
                if (left == dec.front()) {
                    dec.pop_front();
                }
                left++;
            }

            dp[i] = (presum[i - 1] - (left >= 2 ? presum[left - 2] : 0) + MOD) %
                    MOD;
            presum[i] = (presum[i - 1] + dp[i]) % MOD;
        }
        return dp[n] % MOD;
    }
};
// @lc code=end
