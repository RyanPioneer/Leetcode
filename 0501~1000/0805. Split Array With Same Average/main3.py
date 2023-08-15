"""
Source: https://rb.gy/qo4o1
Date: 2023/8/15
Skill:
Ref:
Runtime: 9753 ms, faster than 5.08%
Memory Usage: 67.3 MB, less than 46.19%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 30
    0 <= nums[i] <= 10 ** 4
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right
from functools import cache


class Solution:
    def splitArraySameAverage(self, nums: List[int]) -> bool:
        nums.sort()
        sz, total = len(nums), sum(nums)
        dp = [[False for _ in range(sz + 1)] for _ in range(total + 1)]
        dp[0][0], cur_sum = True, 0
        for num in nums:
            cur_sum += num
            for i in range(cur_sum, num - 1, -1):
                for j in range(sz // 2, 0, -1):
                    if dp[i - num][j - 1]:
                        dp[i][j] = True
                        if j != sz and i * sz == total * j:
                            return True

        return False


if __name__ == "__main__":
    s = Solution()
