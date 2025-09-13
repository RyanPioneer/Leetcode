/*
 * @lc app=leetcode id=3654 lang=cpp
 *
 * [3654] Minimum Sum After Divisible Sum Deletions
 */

// @lc code=start
#define ll long long
class Solution {
   public:
    long long minArraySum(vector<int>& nums, int k) {
        ll presum = 0, res = 0;
        vector<ll> mp(k, -1);
        mp[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i];
            if (mp[presum % k] != -1) {
                res = min(res + nums[i], mp[presum % k]);
                mp[presum % k] = min(mp[presum % k], res);
            } else {
                res += nums[i];
                mp[presum % k] = res;
            }
        }
        return res;
    }
};
// @lc code=end
