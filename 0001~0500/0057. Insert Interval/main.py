"""
Source: https://leetcode.com/problems/insert-interval/
Date: 2023/1/16
Skill:
Ref:
Runtime: 83 ms, faster than 84.86%
Memory Usage: 17.5 MB, less than 24.85%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if intervals == []: return [newInterval]
        if intervals[0][0] > newInterval[1]:
            return [newInterval] + intervals
        for index in range(len(intervals)):
            if intervals[index][1] < newInterval[0]: continue
            index2 = index
            while index2+1 < len(intervals) and intervals[index2][0] <= newInterval[1]: index2 += 1
            if index2+1 == len(intervals) and intervals[index2][0] <= newInterval[1]:
                merged_interval = [min(newInterval[0], intervals[index][0]),
                                   max(newInterval[1], intervals[index2][1])]
                return intervals[:index] + [merged_interval]
            merged_interval = [min(newInterval[0], intervals[index][0]), max(newInterval[1], intervals[index2-1][1])]
            return intervals[:index] + [merged_interval] + intervals[index2:]

        return intervals + [newInterval]