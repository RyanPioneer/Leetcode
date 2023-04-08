"""
Source: https://leetcode.com/problems/frog-jump-ii/
Date: 2023/4/8
Skill:
Ref:
Runtime: 719 ms, faster than 77.29%
Memory Usage: 28.8 MB, less than 76.97%
Time complexity:
Space complexity:
Constraints:
    2 <= stones.length <= 10^5
    stones[0] == 0
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def maxJump(self, stones: List[int]) -> int:
        if len(stones) == 2:
            return stones[1]
        res, sz = 0, len(stones)
        for i in range(sz - 2):
            res = max(res, stones[i + 2] - stones[i])
        return res


if __name__ == "__main__":
    s = Solution()
