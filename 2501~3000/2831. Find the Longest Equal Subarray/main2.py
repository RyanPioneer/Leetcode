"""
Source: https://rb.gy/b64dd
Date: 2023/8/20
Skill:
Runtime: 1589 ms, faster than 100.00%
Memory Usage: 39.7 MB, less than 100.00%
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
    def longestEqualSubarray(self, nums: List[int], k: int) -> int:
        cnt, res, left, sz = defaultdict(int), 0, 0, len(nums)
        for i in range(sz):




if __name__ == "__main__":
    s = Solution()
