"""
Source: https://leetcode.com/problems/find-the-difference/
Date: 2023/2/16
Skill:
Runtime: 30 ms, faster than 91.8%
Memory Usage: 13.9 MB, less than 22.34%
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
    def findTheDifference(self, s: str, t: str) -> str:
        res = 0
        for c in s:
            res ^= ord(c)
        for c in t:
            res ^= ord(c)

        return chr(res)


if __name__ == "__main__":
    s = Solution