"""
Source: https://rb.gy/t9j1k
Date: 2023/7/23
Skill: Note that initially you have nums[0] points!
Ref:
Runtime: 1420 ms, faster than 75.00%
Memory Usage: 37.69 MB, less than 75.00%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def maxScore(self, nums: List[int], x: int) -> int:
        sz = len(nums)
        dp = [[0, 0] for _ in range(sz)]
        dp[0][nums[0] % 2] = nums[0]
        dp[0][(nums[0] + 1) % 2] = nums[0] - x

        for i in range(1, sz):
            dp[i][nums[i] % 2] = nums[i] + max(dp[i - 1][nums[i] % 2], dp[i - 1][(nums[i] + 1) % 2] - x)
            dp[i][(nums[i] + 1) % 2] = dp[i - 1][(nums[i] + 1) % 2]

        return max(dp[-1])


if __name__ == "__main__":
    s = Solution()
    nums, x = [8, 50, 65, 85, 8, 73, 55, 50, 29, 95, 5, 68, 52, 79], 74
    res = s.maxScore(nums, x)
