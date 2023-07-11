"""
Source: https://rb.gy/0414y
Date: 2023/7/11
Skill:
Ref:
Runtime: 88 ms, faster than 84.29%
Memory Usage: 16.3 MB, less than 82.1%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:
        res, sz, left, right = 0, len(s), 0, 0
        while right + 1 < sz and s[right] != s[right + 1]:
            right += 1
        right += 1
        if right + 1 == sz:
            return sz
        res = right
        while right + 1 < sz:
            while right + 1 < sz and s[right] != s[right + 1]:
                right += 1
            res = max(res, right - left + 1)
            right += 1
            while s[left] != s[left + 1]:
                left += 1
            left += 1
        return res


if __name__ == "__main__":
    s = Solution()
