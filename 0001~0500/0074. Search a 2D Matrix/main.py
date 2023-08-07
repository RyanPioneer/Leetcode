"""
Source: https://rb.gy/fubp4
Date: 2023/8/7
Skill:
Ref:
Runtime: 52 ms, faster than 84.30%
Memory Usage: 16.79 MB, less than 90.55%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if matrix[0][0] > target or matrix[-1][-1] < target:
            return False
        lo, hi = 0, len(matrix) - 1
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if matrix[mid][0] > target:
                hi = mid - 1
            else:
                lo = mid
        left, right = 0, len(matrix[0]) - 1
        while left < right:
            mid = (left + right) // 2
            if matrix[lo][mid] == target:
                return True
            elif matrix[lo][mid] < target:
                left = mid + 1
            else:
                right = mid

        return False if matrix[lo][left] != target else True


if __name__ == "__main__":
    s = Solution()
