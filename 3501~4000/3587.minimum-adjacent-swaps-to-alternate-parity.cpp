/*
 * @lc app=leetcode id=3587 lang=cpp
 *
 * [3587] Minimum Adjacent Swaps to Alternate Parity
 */

// @lc code=start
class Solution {
   public:
    int minSwaps(vector<int>& nums) {
        int oddNum = 0, evenNum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                evenNum++;
            } else {
                oddNum++;
            }
        }

        if (abs(oddNum - evenNum) > 1) {
            return -1;
        } else if (oddNum > evenNum) {
            return helper(1, nums);
        } else if (oddNum < evenNum) {
            return helper(0, nums);
        }

        int ans1 = helper(1, nums);
        int ans2 = helper(0, nums);
        return min(ans1, ans2);
    }
    int helper(int oddFirst, vector<int>& nums) {
        int swap = 0, oddNum = 0, evenNum = 0;
        for (auto& i : nums) {
            if (i % 2 == 0) {
                if (evenNum < oddNum) {
                    swap += oddNum - evenNum - oddFirst;
                }
                evenNum++;
            } else {
                if (evenNum > oddNum) {
                    swap += evenNum - oddNum - !oddFirst;
                }
                oddNum++;
            }
        }
        return swap;
    }
};
// @lc code=end
