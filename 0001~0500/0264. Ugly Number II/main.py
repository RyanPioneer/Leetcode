"""
Source: https://rb.gy/gcssw
Date: 2023/7/17
Skill:
Ref:
Runtime: 206 ms, faster than 29.38%
Memory Usage: 16.67 MB, less than 9.63%
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
    def nthUglyNumber(self, n: int) -> int:
        heap, nums, res = [1], set(), []
        nums.add(1)
        heapify(heap)
        while len(res) < n:
            num = heappop(heap)
            res.append(num)
            for i in [2, 3, 5]:
                if num * i not in nums:
                    nums.add(num*i)
                    heappush(heap, num*i)

        return res[-1]


if __name__ == "__main__":
    s = Solution()

