"""
Source: https://rb.gy/hbb42
Date: 2023/8/4
Skill:
Ref:
Runtime: 1431 ms, faster than 65.21%
Memory Usage: 47.58 MB, less than 56.33%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 2000
"""

import math
import sys
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def minCut(self, s: str) -> int:
        sz = len(s)
        is_palindrome, dp = [[False for _ in range(sz)] for _ in range(sz)], [sys.maxsize for _ in range(sz)]
        dp[0] = 0
        for i in range(sz):
            is_palindrome[i][i] = True
        for i in range(sz - 1):
            is_palindrome[i][i + 1] = s[i] == s[i + 1]
        for length in range(3, sz + 1):
            for i in range(sz - length + 1):
                if s[i] == s[i + length - 1]:
                    is_palindrome[i][i + length - 1] = is_palindrome[i + 1][i + length - 2]

        for i in range(1, sz):
            dp[i] = dp[i - 1] + 1
            for j in range(i - 1, -1, -1):
                if is_palindrome[j][i]:
                    if j == 0:
                        dp[i] = 0
                    else:
                        dp[i] = min(dp[i], dp[j - 1] + 1)

        return dp[-1]


if __name__ == "__main__":
    s = Solution()
