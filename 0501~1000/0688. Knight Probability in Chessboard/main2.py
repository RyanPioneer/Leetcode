"""
Source: https://rb.gy/n0x59
Date: 2023/7/22
Skill:
Ref:
Runtime: 493 ms, faster than 5.33%
Memory Usage: 16.43 MB, less than 90.56%
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

        dirs = [[1, 2], [2, 1], [-1, 2], [-2, 1]]
        dp = [[0 for _ in range(n)] for _ in range(n)]
        dp[row][column] = 1
        for _ in range(k):
            dp2 = [[0 for _ in range(n)] for _ in range(n)]
            for i in range(n):
                for j in range(n):
                    for dir in dirs:
                        if check_feasible(i + dir[0], j + dir[1]):
                            dp2[i][j] += dp[i + dir[0]][j + dir[1]] / 8
                        if check_feasible(i - dir[0], j - dir[1]):
                            dp2[i][j] += dp[i - dir[0]][j - dir[1]] / 8
            dp = dp2

        return sum(sum(dp[i]) for i in range(n))


if __name__ == "__main__":
    s = Solution()
    n, k, row, column = 3, 2, 0, 0
    res = s.knightProbability(n, k, row, column)
