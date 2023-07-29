"""
Source: https://rb.gy/5ogjw
Date: 2023/7/29
Skill:
Ref:
Runtime: 410 ms, faster than 10.38%
Memory Usage: 124.04 MB, less than 6.13%
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
    def soupServings(self, n: int) -> float:
        if n > 5000:
            return 1
        dp = [[-1 for _ in range(n + 1)] for _ in range(n + 1)]

        def dfs(a, b):
            if dp[a][b] != -1:
                return dp[a][b]
            if a == 0 and b == 0:
                return 0.5
            elif a == 0 and b > 0:
                return 1
            elif a > 0 and b == 0:
                return 0
            else:
                op1 = dfs(max(a - 100, 0), b)
                op2 = dfs(max(a - 75, 0), max(b - 25, 0))
                op3 = dfs(max(a - 50, 0), max(b - 50, 0))
                op4 = dfs(max(a - 25, 0), max(b - 75, 0))
                dp[a][b] = (op1 + op2 + op3 + op4) * 0.25
                return dp[a][b]

        return dfs(n, n)


if __name__ == "__main__":
    s = Solution()
