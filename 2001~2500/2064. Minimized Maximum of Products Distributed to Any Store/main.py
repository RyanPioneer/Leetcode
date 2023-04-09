"""
Source: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
Date: 2023/4/9
Skill: Binary search
Ref:
Runtime: 2949 ms, faster than 9.6%
Memory Usage: 28.4 MB, less than 77.52%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        lo, hi = 1, sum(quantities)

        def check_available(num):
            total = 0
            for quantity in quantities:
                total += quantity // num
                if quantity % num:
                    total += 1
            return total <= n

        while lo < hi:
            mid = (lo + hi) // 2
            if check_available(mid):
                hi = mid
            else:
                lo = mid + 1

        return lo


if __name__ == "__main__":
    s = Solution()
