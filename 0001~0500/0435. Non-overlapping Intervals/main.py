"""
Source: https://leetcode.com/problems/non-overlapping-intervals/
Date: 2023/1/5
Skill: Greedy
Runtime: 2672 ms, faster than 50.21%
Memory Usage: 51.7 MB, less than 96.29%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda x: x[1])
        res, right = 0, intervals[0][1]
        for index in range(1, len(intervals)):
            if intervals[index][0] < right: res += 1
            else: right = intervals[index][1]

        return res



if __name__ == "__main__":
    s = Solution