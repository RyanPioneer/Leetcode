"""
Source: https://rb.gy/0n3t3
Date: 2023/8/18
Skill:
Ref:
Runtime: 2552 ms, faster than 13.08%
Memory Usage: 30.96 MB, less than 100.00%
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
    def getXORSum(self, arr1: List[int], arr2: List[int]) -> int:
        ones, res = [0 for _ in range(32)], 0
        for num in arr1:
            for i in range(32):
                if (num >> i) & 1 == 1:
                    ones[i] += 1
        for num in arr2:
            n = 0
            for i in range(32):
                if (num >> i) & 1 == 1 and ones[i] % 2 == 1:
                    n += 1 << i
            res ^= n
        return res


if __name__ == "__main__":
    s = Solution()
