"""
Source: https://rb.gy/b0bi5
Date: 2023/7/17
Skill:
Ref:
Runtime: 71 ms, faster than 90.91%
Memory Usage: 16.25 MB, less than 90.91%
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
    def sumOfSquares(self, nums: List[int]) -> int:
        sz, res = len(nums), 0
        for i in range(1, sz + 1):
            if sz % i == 0:
                res += nums[i-1] * nums[i-1]
        return res


if __name__ == "__main__":
    s = Solution()

