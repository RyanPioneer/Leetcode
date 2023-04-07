"""
Source: https://leetcode.com/problems/maximize-win-from-two-segments/
Date: 2023/4/7
Skill:
Ref:
Runtime: 324 ms, faster than 97.29%
Memory Usage: 26.6 MB, less than 94.3%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def maximizeWin(self, prizePositions: List[int], k: int) -> int:
        sz = prizePositions[-1] - prizePositions[0] + 1
        if sz <= 2 * k:
            return len(prizePositions)
        premax, postmax = [0 for _ in range(sz)], [0 for _ in range(sz)]
        pos, mx = 0, 0
        for i in range(len(prizePositions)):
            if prizePositions[i] - prizePositions[pos] > k:



if __name__ == "__main__":
    s = Solution()
