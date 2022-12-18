"""
Source: https://leetcode.com/problems/minimum-path-cost-in-a-grid/
Date: 2022/12/12
Skill: 
Runtime: 3516 ms, faster than 69.56% 
Memory Usage: 19.7 MB, less than 95.34%
Time complexity: 
Space complexity: 
Constraints: 
    2 <= m, n <= 50
"""

from typing import List

class Solution:
    def minPathCost(self, grid: List[List[int]], moveCost: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[0]*n for i in range(2)]
        for i in range(1, m):
            for j in range(n): 
                dp[i%2][j] = min(dp[(i-1)%2][k]+grid[i-1][k]+moveCost[grid[i-1][k]][j] for k in range(n))

        for i in range(0, n):
            dp[(m-1)%2][i] += grid[m-1][i]
        
        return min(dp[(m-1)%2][i] for i in range(n))