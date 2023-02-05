"""
Source: https://leetcode.com/problems/longest-valid-parentheses/
Date: 2023/2/1
Skill: Dynamic Programming
Runtime: 44 ms, faster than 79.68%
Memory Usage: 14.2 MB, less than 74.62%
Time complexity:
Space complexity:
Constraints:
    0 <= s.length <= 3 * 10^4
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def longestValidParentheses(self, s: str) -> int:
        # special case
        if len(s) < 2:
            return 0
        # base case
        dp = [0] * len(s)
        if s[0] == "(" and s[1] == ")":
            dp[1] = 2
        # recursive solution
        for i in range(2,len(s)):
            if s[i] == ")":
                if s[i-1] == "(":
                    dp[i] = dp[i-2] + 2
                if s[i-1] == ")" and (i - dp[i-1] - 1) >= 0 and s[i - dp[i-1] - 1] == "(":
                    if i - dp[i-1] - 2 >= 0:
                        dp[i] = dp[i-1] + 2 + dp[i - dp[i-1] - 2]
                    else:
                        dp[i] = dp[i-1] + 2
        # result
        return max(dp)