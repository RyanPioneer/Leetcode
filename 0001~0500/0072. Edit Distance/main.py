"""
Source: https://leetcode.com/problems/edit-distance/
Date: 2023/2/26
Skill: Dynamic Programming
Ref:
Runtime: 162 ms, faster than 70.5%
Memory Usage: 17.7 MB, less than 20.1%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        word1 = "#" + word1
        word2 = "#" + word2
        dp = [[0 for _ in range(m+1)] for _ in range(n+1)]
        for i in range(1, m+1):
            dp[0][i] = i
        for i in range(1, n+1):
            dp[i][0] = i

        for i in range(1, n+1):
            for j in range(1, m+1):
                if word1[j] == word2[i]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1

        return dp[n][m]


if __name__ == "__main__":
    s = Solution