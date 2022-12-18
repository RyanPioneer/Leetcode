"""
Source: https://leetcode.com/problems/minimum-falling-path-sum-ii/description/
Date: 2022/12/13
Skill: 
Runtime: 420 ms, faster than 83.47% 
Memory Usage: 18.3 MB, less than 27.27%
Time complexity: 
Space complexity: 
Constraints: 
    n == grid.length == grid[i].length
    1 <= n <= 200
    -99 <= grid[i][j] <= 99
"""

from typing import List
import math

class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        min1_value, min2_value, min1_pos, min2_pos = math.inf, math.inf, 0, 0
        for i in range(0, len(grid[0])):
            if grid[0][i] < min1_value: min1_value, min2_value, min1_pos, min2_pos = grid[0][i], min1_value, i, min1_pos
            elif grid[0][i] < min2_value: min2_value, min2_pos = grid[0][i], i
        
        for i in range(1, len(grid)):
            cur_min1_value, cur_min2_value, cur_min1_pos, cur_min2_pos = math.inf, math.inf, 0, 0
            for j in range(0, len(grid[0])):
                if j == min1_pos: grid[i][j] += min2_value
                else: grid[i][j] += min1_value
                if grid[i][j] < cur_min1_value: cur_min1_value, cur_min2_value, cur_min1_pos, cur_min2_pos = grid[i][j], cur_min1_value, j, cur_min1_pos
                elif grid[i][j] < cur_min2_value: cur_min2_value, cur_min2_pos = grid[i][j], j
            min1_value, min2_value, min1_pos, min2_pos = cur_min1_value, cur_min2_value, cur_min1_pos, cur_min2_pos
        
        return min1_value