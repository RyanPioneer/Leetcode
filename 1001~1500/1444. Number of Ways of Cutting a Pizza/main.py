"""
Source: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/
Date: 2023/3/31
Skill: Dynamic programming
Runtime: 399 ms, faster than 26.2%
Memory Usage: 14.7 MB, less than 81.57%
Time complexity:
Space complexity:
Constraints:
    1 <= rows, cols <= 50
    1 <= k <= 10
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        MOD, row, col = 10 ** 9 + 7, len(pizza), len(pizza[0])
        dp = [[[-1 for _ in range(k)] for _ in range(col)] for _ in range(row)]
        tb = [[0 for _ in range(col + 1)] for _ in range(row + 1)]
        for i in range(1, row + 1):
            for j in range(1, col + 1):
                tb[i][j] = int(pizza[i - 1][j - 1] == "A") + tb[i - 1][j] + tb[i][j - 1] - tb[i - 1][j - 1]


        def check_feasible(x1, y1, x2, y2) -> bool:
            return tb[x2 + 1][y2 + 1] - tb[x2 + 1][y1] - tb[x1][y2 + 1] + tb[x1][y1] >= 1

        def dfs(x, y, num):
            if dp[x][y][num] != -1:
                return dp[x][y][num]
            if num == 0:
                if check_feasible(x, y, row - 1, col - 1):
                    dp[x][y][num] = 1
                else:
                    dp[x][y][num] = 0
                return dp[x][y][num]
            total = 0
            for i in range(x + 1, row):
                if check_feasible(x, y, i - 1, col - 1):
                    total += dfs(i, y, num - 1)
            for i in range(y + 1, col):
                if check_feasible(x, y, row - 1, i - 1):
                    total += dfs(x, i, num - 1)

            dp[x][y][num] = total % MOD
            return dp[x][y][num] % MOD

        return dfs(0, 0, k - 1)


if __name__ == "__main__":
    s = Solution()
