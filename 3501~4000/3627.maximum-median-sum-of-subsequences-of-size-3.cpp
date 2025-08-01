/*
 * @lc app=leetcode id=3627 lang=cpp
 *
 * [3627] Maximum Median Sum of Subsequences of Size 3
 */

// @lc code=start
#define ll long long
class Solution {
   public:
    long long maximumMedianSum(vector<int>& nums) {
        ll res = 0, cnt = nums.size();
        sort(begin(nums), end(nums));
        for (int i = cnt - 2; i >= 0 && cnt; i -= 2, cnt -= 3) {
            res += nums[i];
        }
        return res;
    }
};
// @lc code=end
