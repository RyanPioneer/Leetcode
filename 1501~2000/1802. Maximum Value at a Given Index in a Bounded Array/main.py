"""
Source: https://rb.gy/m8h01
Date: 2023/7/23
Skill:
Ref:
Runtime: 54 ms, faster than 58.12%
Memory Usage: 16.38 MB, less than 51.44%
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
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        lo, hi = 1, maxSum

        def count(num):
            total = -num
            if num > index:
                total += (2 * num - index) * (index + 1) // 2
            else:
                total += (1 + num) * num // 2 + (index - num + 1)
            if num >= n - index:
                total += (2 * num - (n - index - 1)) * (n - index) // 2
            else:
                total += (1 + num) * num // 2 + (n - index - num)
            return total

        while lo < hi:
            mid = (lo + hi + 1) // 2
            cnt = count(mid)
            if cnt <= maxSum:
                lo = mid
            else:
                hi = mid - 1

        return lo


if __name__ == "__main__":
    s = Solution()
