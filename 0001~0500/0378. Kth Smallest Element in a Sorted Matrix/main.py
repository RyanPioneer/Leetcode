"""
Source: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
Date: 2023/3/4
Skill:
Runtime: 162 ms, faster than 97.53%
Memory Usage: 18.8 MB, less than 31.83%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools


class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        m, n = len(matrix), len(matrix[0])
        left, right = matrix[0][0], matrix[m-1][n-1]

        def findKthSmallest(num):
            x, y, cnt = m-1, 0, 0
            while x >= 0 and y < n:
                if matrix[x][y] > num:
                    x -= 1
                else:
                    cnt += x + 1
                    y += 1

            return cnt

        while left < right:
            mid = (left + right) // 2
            if findKthSmallest(mid) < k:
                left = mid + 1
            else:
                right = mid

        return left
