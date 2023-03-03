"""
Source: https://leetcode.com/problems/longest-happy-prefix/
Date: 2023/3/4
Skill:
Ref:
Runtime: 295 ms, faster than 68.73%
Memory Usage: 19.1 MB, less than 21.81%
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
    def longestPrefix(self, s: str) -> str:
        dp = [0 for _ in range(len(s))]
        for i in range(1, len(s)):
            j = dp[i-1]
            while j > 0 and s[j] != s[i]:
                j = dp[j-1]
            dp[i] = j + (s[j] == s[i])

        return s[:dp[len(s)-1]]


if __name__ == "__main__":
    s = Solution()
