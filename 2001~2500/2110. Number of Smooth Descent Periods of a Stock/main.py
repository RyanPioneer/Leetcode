"""
Source: https://rb.gy/o3jcr
Date: 2023/7/18
Skill:
Ref:
Runtime: 1090 ms, faster than 60.99%
Memory Usage: 29.95 MB, less than 99.45%
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
    def getDescentPeriods(self, prices: List[int]) -> int:
        res, num, sz = 0, 1, len(prices)
        for i in range(1, sz):
            if prices[i] == prices[i-1] - 1:
                num += 1
            else:
                res += num * (num + 1) // 2
                num = 1
        return res + num * (num + 1) // 2


if __name__ == "__main__":
    s = Solution()
