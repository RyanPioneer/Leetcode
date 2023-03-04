"""
Source: https://leetcode.com/problems/search-a-2d-matrix-ii/
Date: 2023/3/4
Skill:
Runtime: 162 ms, faster than 95.45%
Memory Usage: 20.4 MB, less than 76.35%
Time complexity:
Space complexity:
Constraints:
    1 <= n, m <= 300
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        x, y = m-1, 0
        while x >= 0 and y < n:
            if matrix[x][y] == target:
                return True
            elif matrix[x][y] > target:
                x -= 1
            else:
                y += 1

        return False
