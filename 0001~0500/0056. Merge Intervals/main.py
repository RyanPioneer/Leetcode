"""
Source: https://leetcode.com/problems/merge-intervals/
Date: 2023/1/5
Skill:
Runtime: 152 ms, faster than 86.19%
Memory Usage: 18.9 MB, less than 27.5%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key = lambda x: x[0])
        res, left, right, sz = [], intervals[0][0], intervals[0][1], len(intervals)
        for index in range(1, sz):
            if right >= intervals[index][0]: right = max(right, intervals[index][1])
            else:
                res.append([left, right])
                left, right = intervals[index][0], intervals[index][1]

        res.append([left, right])
        return res


if __name__ == "__main__":
    s = Solution