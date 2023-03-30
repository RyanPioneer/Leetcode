"""
Source: https://leetcode.com/problems/scramble-string/
Date: 2023/3/30
Skill:
Runtime: 162 ms, faster than 28.86%
Memory Usage: 17.4 MB, less than 5.40%
Time complexity:
Space complexity:
Constraints:
    s1.length == s2.length
    1 <= s1.length <= 30
    s1 and s2 consist of lowercase English letters.
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        sz = len(s1)
        dp = [[[-1 for _ in range(sz + 1)] for _ in range(sz)] for _ in range(sz)]

        def dfs(pos1, pos2, length):
            if dp[pos1][pos2][length] != -1:
                return dp[pos1][pos2][length]
            if s1[pos1: pos1 + length] == s2[pos2: pos2 + length]:
                dp[pos1][pos2][length] = True
                return dp[pos1][pos2][length]
            if length == 1:
                dp[pos1][pos2][length] = (s1[pos1] == s2[pos2])
                return dp[pos1][pos2][length]
            flag = False
            for first_length in range(1, length):
                if dfs(pos1, pos2, first_length) and \
                        dfs(pos1 + first_length, pos2 + first_length, length - first_length):
                    flag = True
                    break
                if dfs(pos1, pos2 + length - first_length, first_length) and \
                        dfs(pos1 + first_length, pos2, length - first_length):
                    flag = True
                    break
            dp[pos1][pos2][length] = flag
            return dp[pos1][pos2][length]

        return dfs(0, 0, sz)


if __name__ == "__main__":
    s = Solution()
