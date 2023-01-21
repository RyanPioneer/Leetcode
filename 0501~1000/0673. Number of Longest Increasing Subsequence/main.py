"""
Source: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
Date: 2023/1/20
Skill: Dynamic programming
Ref:
Runtime: 1926 ms, faster than 42.10%
Memory Usage: 14.2 MB, less than 69.37%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 2000
    -10^6 <= nums[i] <= 10^6
"""

from typing import List, Optional
import math

class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        dp, max_num, max_time = [[1, 1] for _ in range(len(nums))], 1, len(nums)
        for i in range(len(nums)):
            for j in range(i):
                if nums[j] < nums[i]:
                    if dp[j][0]+1 > dp[i][0]:
                        dp[i][0] = dp[j][0]+1
                        dp[i][1] = dp[j][1]
                    elif dp[j][0]+1 == dp[i][0]:
                        dp[i][1] += dp[j][1]
                    if dp[j][0]+1 == max_num: max_time += dp[j][1]
                    elif dp[j][0]+1 > max_num:
                        max_num = dp[j][0]+1
                        max_time = dp[j][1]

        return max_time


if __name__ == "__main__":
    string, k = "azaza", 25
    s = Solution