"""
Source: https://rb.gy/f1aau
Date: 2023/8/16
Skill:
Ref:
Runtime: 2580 ms, faster than 5.00%
Memory Usage: 87.44 MB, less than 32.15%
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
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        from sortedcontainers import SortedList
        sl, res, sz = SortedList(), [], len(nums)
        for i in range(k):
            sl.add(nums[i])
        res.append(sl[-1])
        for i in range(k, sz):
            sl.add(nums[i])
            sl.remove(nums[i - k])
            res.append(sl[-1])
        return res


if __name__ == "__main__":
    s = Solution()

