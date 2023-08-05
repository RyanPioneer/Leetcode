"""
Source: https://rb.gy/mp026
Date: 2023/8/4
Skill:
Ref:
Runtime: 3669 ms, faster than 24.10%
Memory Usage: 25.05 MB, less than 7.25%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 2000
"""

import math
import sys
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def longestPalindrome(self, s: str) -> str:
        sz, res = len(s), s[0]
        is_palindrome = [[False for _ in range(sz)] for _ in range(sz)]
        for i in range(sz):
            is_palindrome[i][i] = True
        for i in range(sz - 1):
            if s[i] == s[i + 1]:
                res = s[i: i + 2]
                is_palindrome[i][i + 1] = True
        for length in range(3, sz + 1):
            for i in range(sz - length + 1):
                if s[i] == s[i + length - 1]:
                    is_palindrome[i][i + length - 1] = is_palindrome[i + 1][i + length - 2]
                    if is_palindrome[i][i + length - 1]:
                        res = s[i: i + length]

        return res


if __name__ == "__main__":
    s = Solution()
