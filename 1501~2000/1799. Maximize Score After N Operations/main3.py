"""
Source: https://rb.gy/y3opb
Date: 2023/8/18
Skill:
Ref:
Runtime: 1698 ms, faster than 83.43%
Memory Usage: 25.88 MB, less than 49.72%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 7
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
    def maxScore(self, nums: List[int]) -> int:
        sz = len(nums)
        cand = [i for i in range(sz)]

        @cache
        def dfs(idx, state):
            if idx == sz:
                return 0
            max_val = 0
            for i in range(idx, sz):
                cand[i], cand[idx] = cand[idx], cand[i]
                for j in range(i + 1, sz):
                    cand[j], cand[idx + 1] = cand[idx + 1], cand[j]
                    new_state = state + (1 << cand[idx]) + (1 << cand[idx + 1])
                    val = dfs(idx + 2, new_state) + math.gcd(nums[cand[idx + 1]], nums[cand[idx]]) * (idx + 2) // 2
                    max_val = max(max_val, val)
                    cand[j], cand[idx + 1] = cand[idx + 1], cand[j]
                cand[i], cand[idx] = cand[idx], cand[i]

            return max_val

        return dfs(0, 0)


if __name__ == "__main__":
    s = Solution()
    nums = [1, 2, 3, 4, 5, 6]
    res = s.maxScore(nums)
    print(res)
