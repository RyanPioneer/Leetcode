"""
Source: https://rb.gy/28whm
Date: 2023/7/24
Skill:
Ref:
Runtime: 44 ms, faster than 75.09%
Memory Usage: 16.46 MB, less than 7.14%
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
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            x = 1/x
            n = -n
        if n == 0:
            return 1
        elif x == 0 or n == 1:
            return x
        elif n % 2:
            return x * self.myPow(x ** 2, n // 2)
        else:
            return self.myPow(x ** 2, n // 2)


if __name__ == "__main__":
    s = Solution()
