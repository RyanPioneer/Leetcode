"""
Source: https://rb.gy/loic7
Date: 2023/8/11
Skill:
Ref:
Runtime: 204 ms, faster than 72.97%
Memory Usage: 29.03 MB, less than 60.81%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 1000
    s[i] is either 'a', 'b', 'c', or 'd'.
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def countPalindromicSubsequences(self, s: str) -> int:
        dp, sz, mod, res = [[0 for _ in range(len(s) + 1)] for _ in range(len(s))], len(s), 10 ** 9 + 7, 0
        for i in range(sz):
            dp[i][1] = 1
        for i in range(sz - 1):
            if s[i] == s[i + 1]:
                dp[i + 1][2] = 1
        for length in range(3, sz + 1):
            for i in range(length - 1, sz):
                if s[i] == s[i - length + 1]:
                    dp[i][length] = dp[i - 1][length - 2]
        for i in range(sz):
            res += sum(dp[i])
        return res % mod


if __name__ == "__main__":
    s = Solution()
