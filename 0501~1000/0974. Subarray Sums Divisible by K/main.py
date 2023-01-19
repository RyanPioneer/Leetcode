"""
Source: https://leetcode.com/problems/subarray-sums-divisible-by-k/
Date: 2023/1/19
Skill: Dynamic Programming
Ref:
Runtime: Time Limit Exceeded
Memory Usage:
Time complexity:
Space complexity:
Constraints:
    -10^4 <= nums[i] <= 10^4
"""

from typing import List, Optional
import math


class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        res, sz, dp = 0, len(nums), [[0 for _ in range(k)] for _ in range(2)]
        for num in nums:
            for j in range(k):
                dp[1][(j + num) % k] = dp[0][j]

            dp[1][num % k] += 1
            res += dp[1][0]
            for j in range(k):
                dp[0][j] = dp[1][j]

        return res

if __name__ == "__main__":
    s = Solution
    nums = [0,-5]
    print(s.subarraysDivByK(s, nums, 10))