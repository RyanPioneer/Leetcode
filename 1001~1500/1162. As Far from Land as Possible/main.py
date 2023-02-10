"""
Source: https://leetcode.com/problems/as-far-from-land-as-possible/
Date: 2023/2/10
Skill:
Runtime: 658 ms, faster than 57.44%
Memory Usage: 14.4 MB, less than 96.76%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
import bisect
import heapq
import functools


class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        sz, dir, q = len(grid), [0, 1, 0, -1, 0], deque()
        total_sum = sum(sum(grid[i]) for i in range(sz))
        if total_sum == 0 or total_sum == sz*sz: return -1
        def check_valid(x, y):
            return x >= 0 and x < sz and y >= 0 and y < sz and grid[x][y] == -1

        for i in range(sz):
            for j in range(sz):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    q.append((i, j))
                else:
                    grid[i][j] = -1

        while q:
            cur_x, cur_y = q.popleft()
            for i in range(4):
                if check_valid(cur_x+dir[i], cur_y+dir[i+1]):
                    grid[cur_x+dir[i]][cur_y+dir[i+1]] = grid[cur_x][cur_y]+1
                    q.append((cur_x+dir[i], cur_y+dir[i+1]))

        return max(max(grid[i]) for i in range(sz))


if __name__ == "__main__":
    s = Solution