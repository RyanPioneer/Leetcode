"""
Source: https://rb.gy/affta
Date: 2023/8/10
Skill:
Ref:
Runtime: 736 ms, faster than 29.20%
Memory Usage: 23.94 MB, less than 85.40%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 50
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        n = len(grid)
        dp = [[[-sys.maxsize for _ in range(n + 1)] for _ in range(n + 1)] for _ in range(n + 1)]
        dp[1][1][1] = grid[0][0]
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                for k in range(1, n + 1):
                    if i == 1 and j == 1 and k == 1:
                        continue
                    l = i + j - k
                    if l < 1 or l > n:
                        continue
                    if grid[i - 1][j - 1] == -1 or grid[k - 1][l - 1] == -1:
                        continue
                    if i == k and j == l:
                        num = grid[i - 1][j - 1]
                    else:
                        num = grid[i - 1][j - 1] + grid[k - 1][l - 1]
                    max_prev = max(dp[i - 1][j][k], dp[i - 1][j][k - 1], dp[i][j - 1][k], dp[i][j - 1][k - 1])
                    dp[i][j][k] = max_prev + num

        return max(0, dp[-1][-1][-1])


if __name__ == "__main__":
    s = Solution()
