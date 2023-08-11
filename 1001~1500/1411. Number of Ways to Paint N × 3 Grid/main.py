"""
Source: https://rb.gy/7c399
Date: 2023/8/11
Skill:
Ref:
Runtime: 2859 ms, faster than 8.51%
Memory Usage: 16.85 MB, less than 30.50%
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
    def numOfWays(self, n: int) -> int:
        mod, dp, res = 10 ** 9 + 7, [[[0 for _ in range(3)] for _ in range(3)] for _ in range(3)], 0
        for i in range(27):
            x, y, z = i // 9, i % 9 // 3, i % 3
            if x != y and y != z:
                dp[x][y][z] = 1
        for _ in range(n - 1):
            dp2 = [[[0 for _ in range(3)] for _ in range(3)] for _ in range(3)]
            for i in range(27):
                x, y, z = i // 9, i % 9 // 3, i % 3
                if x != y and y != z:
                    for j in range(27):
                        x2, y2, z2 = j // 9, j % 9 // 3, j % 3
                        if x != x2 and y != y2 and z != z2:
                            dp2[x][y][z] += dp[x2][y2][z2]
            dp = dp2

        for i in range(3):
            for j in range(3):
                res += sum(dp[i][j])
        return res % mod


if __name__ == "__main__":
    s = Solution()
