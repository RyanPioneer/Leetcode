"""
Source: https://leetcode.com/problems/longest-valid-parentheses/
Date: 2023/2/1
Skill: Dynamic Programming
Runtime: 43 ms, faster than 84.22%
Memory Usage: 14.6 MB, less than 60.68%
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
