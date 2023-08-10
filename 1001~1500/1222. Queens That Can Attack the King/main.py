"""
Source: https://rb.gy/gqmlv
Date: 2023/8/10
Skill:
Ref:
Runtime: 41 ms, faster than 96.32%
Memory Usage: 16.38 MB, less than 59.51%
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
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        board, res = [[0 for _ in range(8)] for _ in range(8)], []
        for queen in queens:
            board[queen[0]][queen[1]] = 1
        dirs = [[0, 1], [1, 0], [0, -1], [-1, 0], [1, 1], [-1, 1], [-1, -1], [1, -1]]

        def check_feasible(x, y):
            return 0 <= x < 8 and 0 <= y < 8

        for i in range(len(dirs)):
            x, y = king[0], king[1]
            while check_feasible(x + dirs[i][0], y + dirs[i][1]):
                x, y = x + dirs[i][0], y + dirs[i][1]
                if board[x][y] == 1:
                    res.append([x, y])
                    break

        return res


if __name__ == "__main__":
    s = Solution()
