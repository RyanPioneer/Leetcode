"""
Source: https://leetcode.com/problems/remove-covered-intervals/
Date: 2023/4/15
Skill:
Ref:
Runtime: 95 ms, faster than 75.38%
Memory Usage: 14.4 MB, less than 81.43%
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
from bisect import bisect_left, bisect_right


class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        sz, res, right = len(intervals), len(intervals), intervals[0][1]
        for i in range(1, sz):
            if intervals[i][1] <= right:
                res -= 1
            else:
                right = intervals[i][1]

        return res


if __name__ == "__main__":
    s = Solution()
