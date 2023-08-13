"""
Source: https://rb.gy/jpw9b
Date: 2023/8/13
Skill:
Ref:
Runtime: 3851 ms, faster than 8.33%
Memory Usage: 31.84 MB, less than 100.00%
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
    def minAbsoluteDifference(self, nums: List[int], x: int) -> int:
        sz, res = len(nums), abs(nums[0] - nums[-1])
        from sortedcontainers import SortedList
        sl = SortedList()
        for i in range(sz - x):
            sl.add(nums[i])
            pos = bisect_right(sl, nums[i + x])
            if pos < len(sl):
                res = min(res, abs(nums[i + x] - sl[pos]))
            if pos > 0:
                res = min(res, abs(nums[i + x] - sl[pos - 1]))
        return res


if __name__ == "__main__":
    s = Solution()
