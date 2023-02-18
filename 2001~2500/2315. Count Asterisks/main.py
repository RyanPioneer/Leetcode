"""
Source: https://leetcode.com/problems/count-asterisks/
Date: 2023/2/18
Skill:
Runtime: 32 ms, faster than 74.93%
Memory Usage: 13.9 MB, less than 48.53%
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
    def countAsterisks(self, s: str) -> int:
        res, idx = 0, 1
        for c in s:
            if c == "|":
                idx = (idx+1)%2
            if c == "*" and idx:
                res += 1

        return res


if __name__ == "__main__":
    s = Solution