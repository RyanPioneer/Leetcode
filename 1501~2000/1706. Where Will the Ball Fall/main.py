"""
Source: https://leetcode.com/problems/where-will-the-ball-fall/
Date: 2023/4/1
Skill:
Runtime: 201 ms, faster than 55.86%
Memory Usage: 14.2 MB, less than 98.29%
Time complexity:
Space complexity:
Constraints:
    1 <= m, n <= 100
    grid[i][j] is 1 or -1.
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        row, col, res = len(grid), len(grid[0]), [-1 for _ in range(len(grid[0]))]
        for i in range(col):
            x, y, flag = 0, i, True
            while x < row:
                if grid[x][y] == 1:
                    if y == col - 1 or grid[x][y + 1] == -1:
                        flag = False
                        break
                    else:
                        x += 1
                        y += 1
                else:
                    if y == 0 or grid[x][y - 1] == 1:
                        flag = False
                        break
                    else:
                        x += 1
                        y -= 1

            if flag:
                res[i] = y

        return res


if __name__ == "__main__":
    s = Solution()
