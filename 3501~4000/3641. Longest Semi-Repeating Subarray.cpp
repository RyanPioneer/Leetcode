/*
 * @lc app=leetcode id=3641 lang=cpp
 *
 * [3641] Longest Semi-Repeating Subarray
 */

// @lc code=start

#define ll long long

class Solution {
   public:
    int longestSubarray(vector<int>& nums, int k) {
        int res = 0, num = 0;
        unordered_map<int, int> cnt;
        for (int right = 0, left = 0; right < nums.size(); right++) {
            cnt[nums[right]]++;
            if (cnt[nums[right]] == 2) num++;
            while (num > k) {
                cnt[nums[left]]--;
                if (cnt[nums[left]] == 1) num--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
// @lc code=end
