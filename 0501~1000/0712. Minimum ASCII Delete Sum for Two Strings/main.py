"""
Source: https://rb.gy/jh5bs
Date: 2023/7/31
Skill:
Ref:
Runtime: 522 ms, faster than 83.30%
Memory Usage: 20.89 MB, less than 72.50%
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
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        sz1, sz2 = len(s1), len(s2)
        dp = [[sys.maxsize for _ in range(sz2 + 1)] for _ in range(sz1 + 1)]
        dp[0][0] = 0
        for i in range(1, sz1 + 1):
            dp[i][0] = dp[i - 1][0] + ord(s1[i - 1])
        for i in range(1, sz2 + 1):
            dp[0][i] = dp[0][i - 1] + ord(s2[i - 1])
        for i in range(1, sz1 + 1):
            for j in range(1, sz2 + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = min(dp[i - 1][j] + ord(s1[i - 1]), dp[i][j - 1] + ord(s2[j - 1]))

        return dp[sz1][sz2]


if __name__ == "__main__":
    s = Solution()
