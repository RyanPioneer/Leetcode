"""
Source: https://leetcode.com/problems/maximize-win-from-two-segments/
Date: 2023/4/7
Skill:
Ref:
Runtime: 601 ms, faster than 97.21%
Memory Usage: 25.1 MB, less than 54.60%
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
        sz, res = len(prizePositions), 0
        if prizePositions[-1] - prizePositions[0] + 1 <= 2 * (k + 1):
            return sz
        premax, postmax = [0 for _ in range(sz)], [0 for _ in range(sz)]

        pos, mx = 0, 0
        for i in range(sz):
            while prizePositions[i] - prizePositions[pos] > k:
                pos += 1
            mx = max(mx, i - pos + 1)
            premax[i] = mx

        pos, mx = sz - 1, 0
        for i in range(sz - 1, -1, -1):
            while prizePositions[pos] - prizePositions[i] > k:
                pos -= 1
            mx = max(mx, pos - i + 1)
            postmax[i] = mx

        for i in range(sz - 1):
            res = max(premax[i] + postmax[i + 1], res)

        return res


if __name__ == "__main__":
    s = Solution()
