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
        vector<ll> dp(n, 1), inc, dec;
        inc.push_back(nums[0]);
        dec.push_back(nums[0]);
        unordered_map<int, int> mp;
        for (int i = 1; i < n; i++) {
            dp[i] = 2 * dp[i - 1] % MOD;
            auto mx =
                lower_bound(dec.begin(), dec.end(), nums[i] + k, greater<>());
            auto mi = lower_bound(dec.begin(), dec.end(), nums[i] - k);

            if (mp.find(nums[i - 1]) == mp.end()) {
                mp[nums[i - 1]] = i;
            }
        }
        return dp[n - 1] - dp[n - 2];
    }
};
// @lc code=end
