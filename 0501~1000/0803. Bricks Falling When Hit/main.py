"""
Source: https://rb.gy/ke2lq
Date: 2023/7/25
Skill:
Ref:
Runtime: 2529 ms, faster than 14.61%
Memory Usage: 26.72 MB, less than 51.69%
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
    def hitBricks(self, grid: List[List[int]], hits: List[List[int]]) -> List[int]:
        father, m, n = [i for i in range(len(grid) * len(grid[0]))], len(grid), len(grid[0])
        size = [1 for _ in range(m * n)]

        def find_father(x):
            if father[x] != x:
                father[x] = find_father(father[x])
            return father[x]

        def union(x, y):
            father_x, father_y = find_father(x), find_father(y)
            if father_x != father_y:
                new_father, new_child = min(father_x, father_y), max(father_x, father_y)
                father[new_child] = new_father
                size[new_father] += size[new_child]

        def check_feasible(x, y):
            return 0 <= x < m and 0 <= y < n

        new_grid, hits_size, dirs, res = [], len(hits), [0, 1, 0, -1, 0], [0 for _ in range(len(hits))]
        for i in range(m):
            new_grid.append(grid[i].copy())
        for hit in hits:
            new_grid[hit[0]][hit[1]] = 0
        for i in range(m):
            for j in range(n):
                if new_grid[i][j] == 0:
                    continue
                for k in range(4):
                    new_x, new_y = i + dirs[k], j + dirs[k + 1]
                    if check_feasible(new_x, new_y) and new_grid[new_x][new_y] == 1:
                        union(i * n + j, new_x * n + new_y)

        for i in range(hits_size - 1, -1, -1):
            print(i)
            hit, count = hits[i], 0
            if grid[hit[0]][hit[1]] == 0:
                continue
            new_grid[hit[0]][hit[1]] = 1
            flag = 1 if find_father(hit[0] * n + hit[1]) < n else 0
            for j in range(4):
                new_x, new_y = hit[0] + dirs[j], hit[1] + dirs[j + 1]
                if not check_feasible(new_x, new_y):
                    continue
                if new_grid[new_x][new_y] == 0:
                    continue
                if find_father(new_x * n + new_y) != find_father(hit[0] * n + hit[1]):
                    if find_father(new_x * n + new_y) < n:
                        flag = 1
                    else:
                        count += size[find_father(new_x * n + new_y)]
                    union(new_x * n + new_y, hit[0] * n + hit[1])
            if flag:
                res[i] = count

        return res


if __name__ == "__main__":
    s = Solution()
    grid, hits = [[1], [1], [1], [1], [1]], [[3, 0], [4, 0], [1, 0], [2, 0], [0, 0]]
    res = s.hitBricks(grid, hits)
    print(res)
