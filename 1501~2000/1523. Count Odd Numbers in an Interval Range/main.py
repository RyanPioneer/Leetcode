"""
Source: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
Date: 2023/2/13
Skill:
Runtime: 24 ms, faster than 95.26%
Memory Usage: 13.8 MB, less than 50.4%
Time complexity:
Space complexity:
Constraints:
    0 <= low <= high <= 10^9
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def countOdds(self, low: int, high: int) -> int:
        if low % 2 == 1:
            return (high - low) // 2 + 1
        else:
            return (high - low + 1) // 2


if __name__ == "__main__":
    s = Solution