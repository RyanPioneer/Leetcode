"""
Source: https://leetcode.com/problems/largest-local-values-in-a-matrix/
Date: 2023/2/18
Skill:
Ref:
Runtime: 230 ms, faster than 22.13%
Memory Usage: 14.4 MB, less than 77.66%
Time complexity:
Space complexity:
Constraints:
    n == grid.length == grid[i].length
    3 <= n <= 100
    1 <= grid[i][j] <= 100
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n, res = len(grid), [[0 for _ in range(len(grid)-2)] for _ in range(len(grid)-2)]
        for i in range(n-2):
            for j in range(n-2):
                for k in range(3):
                    for l in range(3):
                        res[i][j] = max(res[i][j], grid[i+k][j+l])

        return res


if __name__ == "__main__":
    s = Solution