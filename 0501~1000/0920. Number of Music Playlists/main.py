"""
Source: https://rb.gy/e8ogy
Date: 2023/8/6
Skill:
Ref:
Runtime: 68 ms, faster than 57.14%
Memory Usage: 16.83 MB, less than 38.35%
Time complexity:
Space complexity:
Constraints:
    0 <= k < n <= goal <= 100
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        mod, dp = 10 ** 9 + 7, [[0 for _ in range(n + 1)] for _ in range(goal + 1)]
        dp[1][1] = n
        for i in range(2, goal + 1):
            for j in range(1, min(i, n) + 1):
                dp[i][j] = dp[i - 1][j - 1] * (n - j + 1)
                if j > k:
                    dp[i][j] += dp[i - 1][j] * (j - k)

        return dp[-1][-1] % mod


if __name__ == "__main__":
    s = Solution()
