"""
Source: https://leetcode.com/problems/removing-stars-from-a-string/
Date: 2023/4/11
Skill:
Ref:
Runtime: 5258 ms, faster than 5.7%
Memory Usage: 15.4 MB, less than 93.9%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def removeStars(self, s: str) -> str:
        pos, star_num = len(s) - 1, 0
        while pos >= 0:
            if s[pos] == "*":
                star_num += 1
                s = s[:pos] + s[pos + 1:]
            elif star_num > 0:
                star_num -= 1
                s = s[:pos] + s[pos + 1:]
            pos -= 1
        return s


if __name__ == "__main__":
    s = Solution()
