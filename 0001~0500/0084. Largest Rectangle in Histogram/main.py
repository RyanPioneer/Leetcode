"""
Source: https://leetcode.com/problems/largest-rectangle-in-histogram/
Date: 2023/3/16
Skill: Monotonic Stack
Runtime: 1253 ms, faster than 16.51%
Memory Usage: 31.3 MB, less than 21.35%
Time complexity:
Space complexity:
Constraints:
    1 <= heights.length <= 10^5
"""

import math
import random
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        prev_smaller, next_smaller = [-1 for i in range(len(heights))], \
            [len(heights) for i in range(len(heights))]
        q1, q2, sz, res = deque(), deque(), len(heights), 0
        for i in range(sz):
            while q1 and heights[q1[-1]] > heights[i]:
                next_smaller[q1[-1]] = i
                q1.pop()
            q1.append(i)
            while q2 and heights[q2[-1]] > heights[sz - i - 1]:
                prev_smaller[q2[-1]] = sz - i - 1
                q2.pop()
            q2.append(sz - i - 1)

        for i in range(sz):
            res = max(res, heights[i] * (next_smaller[i] - prev_smaller[i] - 1))

        return res


if __name__ == "__main__":
    s = Solution()
