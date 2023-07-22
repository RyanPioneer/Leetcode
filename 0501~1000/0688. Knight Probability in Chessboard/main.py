"""
Source: https://rb.gy/n0x59
Date: 2023/7/22
Skill:
Ref:
Runtime:
Memory Usage: Memory Limit Exceeded
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
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        def check_feasible(x, y):
            return 0 <= x < n and 0 <= y < n

        q, res = deque([(row, column, 0)]), 0
        dirs = [[1, 2], [2, 1], [-1, 2], [-2, 1]]
        while q:
            x, y, move = q.popleft()
            if move == k:
                res += 1
                continue
            for dir in dirs:
                if check_feasible(x + dir[0], y + dir[1]):
                    q.append((x + dir[0], y + dir[1], move + 1))
                if check_feasible(x - dir[0], y - dir[1]):
                    q.append((x - dir[0], y - dir[1], move + 1))

        return res / (8 ** k)


if __name__ == "__main__":
    s = Solution()
