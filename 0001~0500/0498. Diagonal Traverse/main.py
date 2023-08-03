"""
Source: https://rb.gy/5tc9x
Date: 2023/8/3
Skill:
Ref:
Runtime: 165 ms, faster than 96.70%
Memory Usage: 20.03 MB, less than 69.46%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        m, n, dir, res, x, y = len(mat), len(mat[0]), True, [], 0, 0
        for _ in range(m * n):
            res.append(mat[x][y])
            if dir:
                if x == 0 or y == n - 1:
                    if x == 0 and y < n - 1:
                        x, y = x, y + 1
                    else:
                        x, y = x + 1, y
                    dir = not dir
                else:
                    x, y = x - 1, y + 1
            else:
                if x == m - 1 or y == 0:
                    if x < m - 1 and y == 0:
                        x, y = x + 1, y
                    else:
                        x, y = x, y + 1
                    dir = not dir
                else:
                    x, y = x + 1, y - 1

        return res


if __name__ == "__main__":
    s = Solution()
