"""
Source: https://leetcode.com/problems/minimum-operations-to-make-array-equal/
Date: 2023/2/13
Skill:
Runtime: 32 ms, faster than 85.67%
Memory Usage: 13.7 MB, less than 95.27%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 10^4
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def minOperations(self, n: int) -> int:
        if n % 2 == 1:
            a0, num = 2, n // 2
        else:
            a0, num = 1, n // 2

        return a0 * num + 2 * num * (num-1) // 2


if __name__ == "__main__":
    s = Solution