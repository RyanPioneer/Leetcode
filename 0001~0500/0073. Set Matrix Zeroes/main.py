"""
Source: https://leetcode.com/problems/set-matrix-zeroes/description/
Date: 2023/2/4
Skill:
Runtime: 127 ms, faster than 89.73%
Memory Usage: 14.8 MB, less than 67.22%
Time complexity:
Space complexity:
Constraints:
    1 <= m, n <= 200
"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m, n, first_col = len(matrix), len(matrix[0]), False
        for i in range(n):
            if matrix[0][i] == 0:
                first_col = True
                break

        for i in range(1, m):
            for j in range(n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0

        for i in range(1, m):
            if matrix[i][0] == 0:
                for j in range(n):
                    matrix[i][j] = 0

        for i in range(n):
            if matrix[0][i] == 0:
                for j in range(m):
                    matrix[j][i] = 0

        if first_col:
            for i in range(n):
                matrix[0][i] = 0