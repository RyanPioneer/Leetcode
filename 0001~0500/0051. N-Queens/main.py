"""
Source: https://leetcode.com/problems/n-queens/
Date: 2023/2/2
Skill: Backtracking
Runtime: 161 ms, faster than 22%
Memory Usage: 14.4 MB, less than 81.76%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 9
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        board, res = [["." for _ in range(n)] for _ in range(n)], []

        def check_valid(x, y):
            for index in range(n):
                if index != x and board[index][y] == "Q":
                    return False
                if x-index-1 >= 0 and y-index-1 >= 0 and board[x-index-1][y-index-1] == "Q":
                    return False
                if x-index-1 >= 0 and y+index+1 < n and board[x-index-1][y+index+1] == "Q":
                    return False

            return True

        def dfs(x):
            for y in range(n):
                if check_valid(x, y):
                    board[x][y] = "Q"
                    if x == n-1:
                        res.append(list("".join(i) for i in board))
                    else:
                        dfs(x+1)
                    board[x][y] = "."

        dfs(0)
        return res