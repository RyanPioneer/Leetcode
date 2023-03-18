"""
Source: https://leetcode.com/problems/partition-equal-subset-sum/
Date: 2023/3/18
Skill:
Runtime: 1499 ms, faster than 45.56%
Memory Usage: 30.5 MB, less than 29.35%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 200
    1 <= nums[i] <= 100
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total, sz = sum(nums), len(nums)
        if total % 2 == 1:
            return False
        dp = [[0 for _ in range(total // 2 + 1)] for _ in range(sz + 1)]
        dp[0][0] = 1
        for i in range(sz):
            for j in range(total // 2 + 1):
                if dp[i][j]:
                    dp[i + 1][j] = 1
                    if j + nums[i] <= total // 2:
                        dp[i + 1][j + nums[i]] = 1
            if dp[i + 1][total // 2]:
                return True

        return False


if __name__ == "__main__":
    s = Solution()
    nums = [14, 9, 8, 4, 3, 2]
    res = s.canPartition(nums)
