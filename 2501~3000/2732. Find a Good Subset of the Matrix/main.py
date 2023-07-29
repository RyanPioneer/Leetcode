"""
Source: https://rb.gy/l9a6f
Date: 2023/7/29
Skill:
Ref:
Runtime: 2102 ms, faster than 15.63%
Memory Usage: 21.48 MB, less than 11.01%
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
    def goodSubsetofBinaryMatrix(self, grid: List[List[int]]) -> List[int]:
        m, n, row2idx = len(grid), len(grid[0]), defaultdict(list)
        for i in range(m):
            num = 0
            for j in range(n):
                if grid[i][j] == 1:
                    num += 1 << j
            if num == 0:
                return [i]
            row2idx[num].append(i)

        for i in range(m):
            for j in range(1 << n):
                flag = True
                for k in range(n):
                    if grid[i][k] and (j >> k) & 1:
                        flag = False
                        break
                if flag and j in row2idx:
                    print(i, j)
                    return sorted([i, row2idx[j][0]])

        return []


if __name__ == "__main__":
    s = Solution()
    grid = [[1, 0, 0, 1, 0], [1, 0, 1, 0, 1], [0, 0, 0, 0, 1], [1, 0, 1, 1, 1]]
    res = s.goodSubsetofBinaryMatrix(grid)
    print(res)
