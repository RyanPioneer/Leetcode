"""
Source: https://rb.gy/l04pk
Date: 2023/8/24
Skill:
Runtime: 327 ms, faster than 55.33%
Memory Usage: 21.7 MB, less than 70.36%
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


class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        sz, dp = len(nums), [0, -sys.maxsize, -sys.maxsize]
        for i in range(sz):
            dp2 = dp.copy()
            for j in range(3):
                dp[j] = max(dp2[j], dp2[(j + 3 - nums[i] % 3) % 3] + nums[i])
        return dp[0]


if __name__ == "__main__":
    s = Solution()
