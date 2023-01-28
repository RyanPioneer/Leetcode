"""
Source: https://leetcode.com/problems/data-stream-as-disjoint-intervals/
Date: 2023/1/28
Skill: Binary Search
Runtime: 195 ms, faster than 56.19%
Memory Usage: 18.9 MB, less than 99%
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
        self.interval = []

    def addNum(self, value: int) -> None:
        left, right = 0, len(self.interval)-1
        while left <= right:
            mid = (left + right) // 2
            if self.interval[mid][0] <= value <= self.interval[mid][1]: return
            if self.interval[mid][0] > value: right = mid-1
            else: left = mid+1

        self.interval.insert(left, [value, value])
        if left < len(self.interval)-1 and value+1 == self.interval[left+1][0]:
            self.interval[left + 1][0] = value
            del self.interval[left]
        if left > 0 and value-1 == self.interval[left-1][1]:
            self.interval[left - 1][1] = self.interval[left][1]
            del self.interval[left]


    def getIntervals(self) -> List[List[int]]:
        return self.interval

# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(value)
# param_2 = obj.getIntervals()