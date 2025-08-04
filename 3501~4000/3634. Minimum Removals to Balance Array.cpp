/*
 * @lc app=leetcode id=3634 lang=cpp
 *
 * [3634] Minimum Removals to Balance Array
 */

// @lc code=start

#define ll long long

class Solution {
   public:
    int minRemoval(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int lo = 0, hi = nums.size();
        while (lo != hi) {
            int mid = (lo + hi + 1) / 2;
            if (canBalance(nums, mid, k)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return nums.size() - hi;
    }
    bool canBalance(vector<int>& nums, int mid, int k) {
        for (int i = 0; i + mid - 1 < nums.size(); i++) {
            if (nums[i + mid - 1] <= (ll)nums[i] * k) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
