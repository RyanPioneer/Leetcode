"""
Source: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
Date: 2023/4/22
Skill:
Ref:
Runtime: 177 ms, faster than 40.65%
Memory Usage: 14.9 MB, less than 53.27%
Time complexity:
Space complexity:
Constraints:
    1 <= s.length <= 10 ** 5
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def minInsertions(self, s: str) -> int:
        res, pos, left, sz = 0, 0, 0, len(s)
        while pos < sz:
            if s[pos] == "(":
                left += 1
            else:
                if pos + 1 < sz and s[pos + 1] == ")":
                    left -= 1
                    pos += 1
                else:
                    left -= 1
                    res += 1
                if left < 0:
                    left = 0
                    res += 1
            pos += 1

        return res + left * 2


if __name__ == "__main__":
    s = Solution()
