"""
Source: https://rb.gy/a6yuv
Date: 2023/8/21
Skill: KMP
Ref:
Runtime: 125 ms, faster than 31.51%
Memory Usage: 16.89 MB, less than 7.19%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 10 ** 4
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right
from functools import cache


class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        dp, sz = [0 for _ in range(len(s))], len(s)
        for i in range(1, sz):
            pos = dp[i - 1]
            while pos > 0 and s[pos] != s[i]:
                pos = dp[pos - 1]
            dp[i] = pos + (s[pos] == s[i])
        return dp[-1] > 0 and sz % (sz - dp[-1]) == 0


if __name__ == "__main__":
    s = Solution()

