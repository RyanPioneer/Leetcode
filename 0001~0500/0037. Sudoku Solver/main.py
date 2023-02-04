"""
Source: https://leetcode.com/problems/sudoku-solver/
Date: 2023/2/2
Skill: Backtracking
Runtime: 571 ms, faster than 36.63%
Memory Usage: 13.9 MB, less than 69.88%
Time complexity:
Space complexity:
Constraints:
    board.length == 9
    It is guaranteed that the input board has only one solution.
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        def check_valid(x, y, k):
            for index in range(9):
                if index != x and board[index][y] == k:
                    return False
                if index != y and board[x][index] == k:
                    return False
                cur_x, cur_y = x//3*3+index//3, y//3*3+index%3
                if (x != cur_x or y != cur_y) and board[cur_x][cur_y] == k:
                    return False

            return True

        def dfs(x, y):
            if board[x][y] == ".":
                for num in range(1, 10):
                    if check_valid(x, y, str(num)):
                        board[x][y] = str(num)
                        if y == 8:
                            if x == 8:
                                return True
                            else:
                                if dfs(x+1, 0):
                                    return True
                        else:
                            if dfs(x, y+1):
                                return True
                        board[x][y] = "."
                return False
            else:
                if y == 8:
                    if x == 8:
                        return True
                    else:
                        if dfs(x + 1, 0):
                            return True
                else:
                    if dfs(x, y + 1):
                        return True
                return False

        dfs(0, 0)