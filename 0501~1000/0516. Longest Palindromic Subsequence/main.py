"""
Source: https://leetcode.com/problems/longest-palindromic-subsequence/description/
Date: 2023/2/7
Skill: Dynamic Programming
Runtime: 1958 ms, faster than 54.83%
Memory Usage: 31.4 MB, less than 57.54%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 1000
    s consists only of lowercase English letters.
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        dp, sz = [[0 for _ in range(len(s)+1)] for _ in range(len(s)+1)], len(s)
        for i in range(sz):
            dp[i][i] = 1

        for length in range(1, sz):
            for head in range(sz-length):
                tail = head+length
                if s[head] == s[tail]:
                    dp[head][tail] = dp[head+1][tail-1]+2
                else:
                    dp[head][tail] = max(dp[head][tail-1], dp[head+1][tail])

        return dp[0][sz-1]

if __name__ == "__main__":
    s = Solution