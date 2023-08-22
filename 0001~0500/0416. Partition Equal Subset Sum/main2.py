"""
Source: https://leetcode.com/problems/partition-equal-subset-sum/
Date: 2023/8/22
Skill:
Runtime: 743 ms, faster than 68.83%
Memory Usage: 16.42 MB, less than 88.65%
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
        dp = [False for _ in range(total // 2 + 1)]
        dp[0] = True
        for i in range(sz):
            for j in range(total // 2 - nums[i], -1, -1):
                if dp[j]:
                    dp[j + nums[i]] = dp[j]

        return dp[-1]


if __name__ == "__main__":
    s = Solution()
    nums = [14, 9, 8, 4, 3, 2]
    res = s.canPartition(nums)
