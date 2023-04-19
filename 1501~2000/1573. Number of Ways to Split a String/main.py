"""
Source: https://leetcode.com/problems/number-of-ways-to-split-a-string/
Date: 2023/4/19
Skill:
Ref:
Runtime: 149 ms, faster than 45.39%
Memory Usage: 14.9 MB, less than 75.66%
Time complexity:
Space complexity:
Constraints:
    3 <= s.length <= 10^5
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def numWays(self, s: str) -> int:
        MOD, sz, total = 10 ** 9 + 7, len(s), 0
        for c in s:
            if c == "1":
                total += 1

        if total == 0:
            return (sz - 1) * (sz - 2) // 2 % MOD

        if total % 3 != 0:
            return 0

        start, end, left, right, pre, suf = 0, sz - 1, 1, 1, 0, 0
        while pre < total // 3:
            if s[start] == "1":
                pre += 1
            start += 1
        while s[start] != "1":
            left += 1
            start += 1

        while suf < total // 3:
            if s[end] == "1":
                suf += 1
            end -= 1
        while s[end] != "1":
            right += 1
            end -= 1

        return left * right % MOD


if __name__ == "__main__":
    s = Solution()
