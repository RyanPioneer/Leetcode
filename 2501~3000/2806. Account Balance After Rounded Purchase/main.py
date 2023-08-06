"""
Source: https://rb.gy/lq7a9
Date: 2023/8/6
Skill:
Ref:
Runtime: 41 ms, faster than 66.67%
Memory Usage: 16.38 MB, less than 33.33%
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
    def accountBalanceAfterPurchase(self, purchaseAmount: int) -> int:
        lo = purchaseAmount - purchaseAmount % 10
        if purchaseAmount - lo < 5:
            return 100 - lo
        else:
            return 100 - lo - 10


if __name__ == "__main__":
    s = Solution()
