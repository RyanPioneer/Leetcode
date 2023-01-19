"""
Source: https://leetcode.com/problems/maximum-product-subarray/
Date: 2023/1/19
Skill: Dynamic Programming
Ref:
Runtime: 85 ms, faster than 86.13%
Memory Usage: 14.2 MB, less than 99.3%
Time complexity:
Space complexity:
Constraints:
    -10 <= nums[i] <= 10
"""

from typing import List, Optional
import math

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        dp, res = [nums[0], nums[0]], nums[0]
        for i in range(1, len(nums)):
            if nums[i] > 0:
                dp[0], dp[1] = max(nums[i], nums[i]*dp[0]), min(nums[i], nums[i]*dp[1])
            else:
                dp[0], dp[1] = max(nums[i], nums[i] * dp[1]), min(nums[i], nums[i] * dp[0])
            res = max(res, dp[0])

        return res

if __name__ == "__main__":
    nums = [-4,-3,-2]
    s = Solution
    print(s.maxProduct(s, nums))