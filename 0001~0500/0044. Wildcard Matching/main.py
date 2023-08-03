"""
Source: https://leetcode.com/problems/wildcard-matching/
Date: 2023/8/3
Skill: Dynamic Programming
Runtime: 2104 ms, faster than 72.4%
Memory Usage: 24.2 MB, less than 39.78%
Time complexity:
Space complexity:
Constraints:

"""

import math
import random
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        s, p = "#" + s, "#" + p
        dp = [[0 for _ in range(len(p))] for _ in range(len(s))]
        dp[0][0] = 1

        for i in range(len(p) - 1):
            if p[i + 1] != "*":
                break
            dp[0][i + 1] = 1

        for i in range(1, len(s)):
            for j in range(1, len(p)):
                if s[i] == p[j] or p[j] == "?":
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j] == "*":
                    dp[i][j] = dp[i - 1][j] or dp[i][j - 1]

        return dp[-1][-1] == 1


if __name__ == "__main__":
    s = Solution()
