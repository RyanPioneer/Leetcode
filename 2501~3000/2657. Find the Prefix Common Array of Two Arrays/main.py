"""
Source: https://rb.gy/mkevt
Date: 2023/7/8
Skill:
Ref:
Runtime: 152 ms, faster than 65.11%
Memory Usage: 16.3 MB, less than 44.14%
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
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        res, set_a, set_b = [0 for _ in range(len(A))], set(), set()
        set_a.add(A[0])
        set_b.add(B[0])
        if A[0] == B[0]:
            res[0] = 1
        for i in range(1, len(A)):
            res[i] = res[i-1]
            if A[i] in set_b:
                res[i] += 1
            set_a.add(A[i])
            if B[i] in set_a:
                res[i] += 1
            set_b.add(B[i])
        return res


if __name__ == "__main__":
    s = Solution()

