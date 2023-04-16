"""
Source: https://leetcode.com/problems/count-fertile-pyramids-in-a-land/
Date: 2023/4/16
Skill: Dynamic Programming
Ref:
Runtime: 1594 ms, faster than 44.93%
Memory Usage: 23.6 MB, less than 31.88%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def countPyramids(self, grid: List[List[int]]) -> int:
        row, col, res = len(grid), len(grid[0]), 0
        left, right = [[grid[i][j] for j in range(col)] for i in range(row)], \
            [[grid[i][j] for j in range(col)] for i in range(row)]
        dp1, dp2 = [[0 for _ in range(col)] for _ in range(row)], \
            [[0 for _ in range(col)] for _ in range(row)]

        for i in range(row):
            for j in range(1, col):
                if left[i][j] == 1:
                    left[i][j] += left[i][j - 1]
                if right[i][col - j - 1] == 1:
                    right[i][col - j - 1] += right[i][col - j]

        for i in range(col):
            dp1[0][i] = grid[0][i]
            dp2[row - 1][i] = grid[row - 1][i]

        for i in range(1, row):
            for j in range(1, col - 1):
                dp1[i][j] = min(left[i][j], right[i][j], dp1[i - 1][j] + 1)
                if dp1[i][j] > 1:
                    res += dp1[i][j] - 1
                dp2[row - i - 1][j] = min(left[row - i - 1][j], right[row - i - 1][j], dp2[row - i][j] + 1)
                if dp2[row - i - 1][j] > 1:
                    res += dp2[row - i - 1][j] - 1

        return res


if __name__ == "__main__":
    s = Solution()
