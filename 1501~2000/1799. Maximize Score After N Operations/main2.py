"""
Source: https://rb.gy/y3opb
Date: 2023/8/18
Skill:
Ref:
Runtime: TLE
Memory Usage:
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
        sz, res = len(nums), 0
        cand = [i for i in range(sz)]

        # @cache
        def dfs(idx, score):
            nonlocal res
            if idx == sz:
                res = max(res, score)
                return
            for i in range(idx, sz):
                cand[i], cand[idx] = cand[idx], cand[i]
                for j in range(i + 1, sz):
                    cand[j], cand[idx + 1] = cand[idx + 1], cand[j]
                    dfs(idx + 2, score + math.gcd(nums[cand[idx + 1]], nums[cand[idx]]) * (idx + 2) // 2)
                    cand[j], cand[idx + 1] = cand[idx + 1], cand[j]
                cand[i], cand[idx] = cand[idx], cand[i]

        dfs(0, 0)
        return res


if __name__ == "__main__":
    s = Solution()
    nums = [3, 4, 6, 8]
    res = s.maxScore(nums)
    print(res)
