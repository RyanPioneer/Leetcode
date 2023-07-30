"""
Source: https://rb.gy/lj2b1
Date: 2023/7/30
Skill:
Ref:
Runtime: 460 ms, faster than 76.77%
Memory Usage: 16.3 MB, less than 100.00%
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
    def strangePrinter(self, s: str) -> int:
        sz, dp = len(s), [[sys.maxsize for _ in range(len(s))] for _ in range(len(s))]
        for i in range(sz):
            dp[i][i] = 1
        for length in range(2, sz + 1):
            for i in range(sz - length + 1):
                dp[i][i + length - 1] = dp[i + 1][i + length - 1] + 1
                for j in range(i + 1, i + length - 1):
                    if s[i] == s[j]:
                        dp[i][i + length - 1] = min(dp[i][i + length - 1], dp[i][j - 1] + dp[j + 1][i + length - 1])
                if s[i] == s[i + length - 1]:
                    dp[i][i + length - 1] = min(dp[i][i + length - 1], dp[i][i + length - 2])

        return dp[0][sz - 1]


if __name__ == "__main__":
    s = Solution()
