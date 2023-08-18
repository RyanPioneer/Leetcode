"""
Source: https://rb.gy/y3opb
Date: 2023/8/18
Skill:
Ref:
Runtime:
Memory Usage: MLE
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

        @cache
        def dfs(idx, score, cand):
            nonlocal res
            if idx == sz:
                res = max(res, score)
                return
            cand_list = list(cand)
            for i in range(idx, sz):
                cand_list[i], cand_list[idx] = cand_list[idx], cand_list[i]
                for j in range(i + 1, sz):
                    cand_list[j], cand_list[idx + 1] = cand_list[idx + 1], cand_list[j]
                    dfs(idx + 2, score + math.gcd(nums[cand_list[idx + 1]], nums[cand_list[idx]]) * (idx + 2) // 2, tuple(cand_list))
                    cand_list[j], cand_list[idx + 1] = cand_list[idx + 1], cand_list[j]
                cand_list[i], cand_list[idx] = cand_list[idx], cand_list[i]

        dfs(0, 0, (i for i in range(sz)))
        return res


if __name__ == "__main__":
    s = Solution()
    nums = [3, 4, 6, 8]
    res = s.maxScore(nums)
    print(res)
