"""
Source: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
Date: 2023/4/1
Skill:
Runtime: 780 ms, faster than 56.32%
Memory Usage: 16.1 MB, less than 56.98%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 500
    s consists of lowercase English letters.
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def minInsertions(self, s: str) -> int:
        sz = len(s)
        dp = [[0 for _ in range(sz)] for _ in range(sz)]
        for length in range(2, sz + 1):
            for i in range(sz - length + 1):
                j = i + length - 1
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1]
                else:
                    dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1

        return dp[0][sz - 1]


if __name__ == "__main__":
    s = Solution()
