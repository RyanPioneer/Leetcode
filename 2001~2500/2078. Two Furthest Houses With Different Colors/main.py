"""
Source: https://leetcode.com/problems/two-furthest-houses-with-different-colors/description/
Date: 2023/2/12
Skill:
Runtime: 33 ms, faster than 95.46%
Memory Usage: 13.8 MB, less than 50.30%
Time complexity:
Space complexity:
Constraints:
    2 <= nums.length <= 100
    Test data are generated such that at least two houses have different colors.
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
import bisect
import heapq
import functools


class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        left, right, sz = 0, len(colors) - 1, len(colors)
        while colors[right] == colors[0]: right -= 1
        while colors[left] == colors[sz-1]: left += 1
        return max(right, sz-1-left)


if __name__ == "__main__":
    s = Solution