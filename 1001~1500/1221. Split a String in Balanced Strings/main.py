"""
Source: https://leetcode.com/problems/split-a-string-in-balanced-strings/
Date: 2023/2/17
Skill:
Runtime: 37 ms, faster than 42.73%
Memory Usage: 13.8 MB, less than 95.11%
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
    def balancedStringSplit(self, s: str) -> int:
        l_num, r_num, sz, res = 0, 0, len(s), 0
        for i in range(sz):
            if s[i] == "L":
                l_num += 1
            else:
                r_num += 1
            if l_num == r_num:
                res += 1
        return res


if __name__ == "__main__":
    s = Solution