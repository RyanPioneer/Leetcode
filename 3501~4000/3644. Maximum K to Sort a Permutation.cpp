/*
 * @lc app=leetcode id=3644 lang=cpp
 *
 * [3644] Maximum K to Sort a Permutation
 */

// @lc code=start
class Solution {
   public:
    int sortPermutation(vector<int>& nums) {
        int target = 0;
        for (auto& i : nums) {
            target |= i;
        }
        int res = target;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                res &= nums[i];
            }
        }
        return res == target ? 0 : res;
    }
};
// @lc code=end
