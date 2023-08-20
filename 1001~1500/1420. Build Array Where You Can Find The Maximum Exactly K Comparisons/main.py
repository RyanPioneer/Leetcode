"""
Source: https://rb.gy/1vycg
Date: 2023/8/19
Skill:
Ref:
Runtime: 1197 ms, faster than 51.61%
Memory Usage: 20.44 MB, less than 66.13%
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
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        # * dp[i][j][k]表示對於前i個元素、最大值等於j、總共用了k次cost時，總共有多少種方案
        mod, dp, res = 10 ** 9 + 7, [[[0 for _ in range(k + 1)] for _ in range(m)] for _ in range(n)], 0
        for i in range(m):
            dp[0][i][1] = 1
        for i in range(1, n):
            for j in range(m):
                for l in range(1, k + 1):
                    dp[i][j][l] = dp[i - 1][j][l] * (j + 1)
                    for t in range(0, j):
                        dp[i][j][l] += dp[i - 1][t][l - 1]
                    dp[i][j][l] %= mod

        for i in range(k - 1, m):
            res = (res + dp[-1][i][-1]) % mod
        return res


if __name__ == "__main__":
    s = Solution()
