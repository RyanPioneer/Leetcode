"""
Source: https://rb.gy/6m3fw
Date: 2023/8/17
Skill:
Ref:
Runtime: 2375 ms, faster than 32.95%
Memory Usage: 179.57 MB, less than 39.77%
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
        dp = [[[-1 for _ in range(m + n + 1)] for _ in range(n)] for _ in range(m)]

        def dfs(x, y, cur_sum):
            if grid[x][y] == "(":
                cur_sum += 1
            else:
                cur_sum -= 1
            if dp[x][y][cur_sum] != -1:
                if dp[x][y][cur_sum] == 1:
                    return True
                else:
                    return False
            if x == m - 1 and y == n - 1:
                if cur_sum == 0:
                    dp[x][y][cur_sum] = 1
                else:
                    dp[x][y][cur_sum] = 0
                return dp[x][y][cur_sum]
            if cur_sum < 0:
                dp[x][y][cur_sum] = 0
                return False
            if x < m - 1:
                if dfs(x + 1, y, cur_sum):
                    dp[x][y][cur_sum] = 1
                    return True
            if y < n - 1:
                if dfs(x, y + 1, cur_sum):
                    dp[x][y][cur_sum] = 1
                    return True
            dp[x][y][cur_sum] = 0
            return False

        return dfs(0, 0, 0)


if __name__ == "__main__":
    s = Solution()
