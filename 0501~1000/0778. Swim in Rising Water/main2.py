"""
Source: https://rb.gy/7k51l
Date: 2023/8/21
Skill: Binary search + BFS
Ref:
Runtime: 192 ms, faster than 10.77%
Memory Usage: 16.92 MB, less than 67.93%
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
from functools import cache


class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n, lo, hi = len(grid), max(grid[0][0], grid[-1][-1]), 0
        dirs = [0, 1, 0, -1, 0]
        for i in range(n):
            for j in range(n):
                hi = max(hi, grid[i][j])

        def check_feasible(height):
            visited = defaultdict(int)
            visited[(0, 0)] = 1
            q = deque([[0, 0]])
            while q:
                x, y = q.popleft()
                if x == n - 1 and y == n - 1:
                    return True
                for i in range(4):
                    next_x, next_y = x + dirs[i], y + dirs[i + 1]
                    if 0 <= next_x < n and 0 <= next_y < n and (next_x, next_y) not in visited and grid[next_x][next_y] <= height:
                        visited[(next_x, next_y)] = 1
                        q.append([next_x, next_y])
            return False

        while lo < hi:
            mid = (lo + hi) // 2
            if check_feasible(mid):
                hi = mid
            else:
                lo = mid + 1

        return lo


if __name__ == "__main__":
    s = Solution()
