"""
Source: https://leetcode.com/problems/trapping-rain-water/
Date: 2023/3/10
Skill:
Runtime: 316 ms, faster than 5.3%
Memory Usage: 16.2 MB, less than 9.69%
Time complexity:
Space complexity:
Constraints:

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
    def trap(self, height: List[int]) -> int:
        left, right, h1, h2, sz, res = [], [], 0, 0, len(height), 0
        for i in range(sz):
            if height[i] > h1:
                h1 = height[i]
            left.append(h1)
            if height[sz-i-1] > h2:
                h2 = height[sz-i-1]
            right.insert(0, h2)

        for i in range(1, sz-1):
            if min(left[i], right[i]) > height[i]:
                res += min(left[i], right[i]) - height[i]

        return res


if __name__ == "__main__":
    s = Solution()
