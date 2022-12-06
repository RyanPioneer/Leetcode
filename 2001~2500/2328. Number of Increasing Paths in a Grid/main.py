"""
Source: https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/
Date: 2022/12/6
Skill: Dynamic Programming
Runtime: 2976 ms, faster than 82.84% 
Memory Usage: 144.4 MB, less than 14.56%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= m, n <= 1000
    1 <= grid[i][j] <= 10^5
"""

from typing import List

class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        MOD = 1000000007
        dp = [[0 for i in range(len( grid[0]))] for j in range(len( grid))]
        dir = [[0,1],[0,-1],[1,0],[-1,0]]
        res = 0
        
        def check_valid(x,y):
            if x>=0 and x<len(grid) and y>=0 and y<len(grid[0]):
                return True
            return False
        
        def bfs(i,j):
            if dp[i][j] == 0:
                l = 0
                for dirx, diry in dir:
                    if check_valid(i+dirx,j+diry) and grid[i][j]<grid[i+dirx][j+diry]:
                        l += bfs(i+dirx,j+diry)
                dp[i][j] += l+1
        
            return dp[i][j]    
            
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                res = (res+bfs(i,j))%MOD
                
        return res