"""
Source: https://rb.gy/6m3fw
Date: 2023/8/17
Skill:
Ref:
Runtime: 1285 ms, faster than 65.91%
Memory Usage: 229.87 MB, less than 38.64%
Time complexity:
Space complexity:
Constraints:
    1 <= m, n <= 100
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
    def hasValidPath(self, grid: List[List[str]]) -> bool:
        if grid[0][0] == ")" or grid[-1][-1] == "(":
            return False
        m, n = len(grid), len(grid[0])

        @cache
        def dfs(x, y, cur_sum):
            if grid[x][y] == "(":
                cur_sum += 1
            else:
                cur_sum -= 1
            if x == m - 1 and y == n - 1:
                return cur_sum == 0
            if cur_sum < 0:
                return False
            if x < m - 1:
                if dfs(x + 1, y, cur_sum):
                    return True
            if y < n - 1:
                if dfs(x, y + 1, cur_sum):
                    return True
            return False

        return dfs(0, 0, 0)


if __name__ == "__main__":
    s = Solution()
