"""
Source: https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/
Date: 2023/4/7
Skill:
Ref:
Runtime: 31 ms, faster than 69.90%
Memory Usage: 13.9 MB, less than 55.48%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 10^5
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def minOperations(self, n: int) -> int:
        res = 0

        def count(num):
            return bin(num).count("1")

        for i in range(31):
            if count(n + (1 << i)) < count(n):
                n += (1 << i)
                res += 1

        return res + count(n)


if __name__ == "__main__":
    s = Solution()
