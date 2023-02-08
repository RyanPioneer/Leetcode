"""
Source: https://leetcode.com/problems/delete-operation-for-two-strings/
Date: 2023/2/8
Skill: Dynamic Programming
Runtime: 290 ms, faster than 60.13%
Memory Usage: 17.8 MB, less than 36.36%
Time complexity:
Space complexity:
Constraints:
    1 <= word1.length, word2.length <= 500
    word1 and word2 consist of only lowercase English letters.
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        len1, len2 = len(word1), len(word2)
        dp = [[math.inf for _ in range(len2 + 1)] for _ in range(len1 + 1)]
        for i in range(len1 + 1):
            dp[i][0] = i
        for i in range(len2 + 1):
            dp[0][i] = i

        for i in range(1, len1 + 1):
            for j in range(1, len2 + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1

        return int(dp[len1][len2])


if __name__ == "__main__":
    s = Solution