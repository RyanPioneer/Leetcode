"""
Source: https://leetcode.com/problems/sort-integers-by-the-power-value/
Date: 2023/3/30
Skill:
Runtime: 171 ms, faster than 85.47%
Memory Usage: 27.6 MB, less than 20.63%
Time complexity:
Space complexity:
Constraints:
    1 <= lo <= hi <= 1000
    1 <= k <= hi - lo + 1
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        memo, num2value, nums = defaultdict(int), {}, [i for i in range(lo, hi + 1)]

        def dfs(val):
            if val == 1:
                return 0
            if val in memo:
                return memo[val]
            if val % 2 == 1:
                memo[val] = dfs(3 * val + 1) + 1
            else:
                memo[val] = dfs(val // 2) + 1
            return memo[val]

        for i in range(lo, hi + 1):
            num2value[i] = dfs(i)

        nums.sort(key=lambda x: num2value[x])
        return nums[k-1]


if __name__ == "__main__":
    s = Solution()
