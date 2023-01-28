"""
Source: https://leetcode.com/problems/data-stream-as-disjoint-intervals/
Date: 2023/1/28
Skill:
Runtime: 840 ms, faster than 16.6%
Memory Usage: 19 MB, less than 75.92%
Time complexity:
Space complexity:
Constraints:
    0 <= value <= 10^4
    At most 3 * 10^4 calls will be made to addNum and getIntervals.
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools

class SummaryRanges:

    def __init__(self):
        self.nums = set()
    def addNum(self, value: int) -> None:
        self.nums.add(value)

    def getIntervals(self) -> List[List[int]]:
        seen, res = set(), []
        for num in self.nums:
            if num in seen:
                continue
            left, right = num, num
            seen.add(num)
            while left-1 in self.nums:
                left -= 1
                seen.add(left)
            while right+1 in self.nums:
                right += 1
                seen.add(right)
            res.append([left, right])

        return sorted(res)

# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(value)
# param_2 = obj.getIntervals()