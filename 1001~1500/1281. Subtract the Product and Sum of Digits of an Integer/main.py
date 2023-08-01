"""
Source: https://rb.gy/1jyb9
Date: 2023/7/31
Skill:
Ref:
Runtime: 47 ms, faster than 50.07%
Memory Usage: 16.23 MB, less than 63.23%
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
    def subtractProductAndSum(self, n: int) -> int:
        s, product, addition = str(n), 1, 0
        for c in s:
            product *= int(c)
            addition += int(c)
        return product - addition


if __name__ == "__main__":
    s = Solution()
