"""
Source: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
Date: 2022/12/6
Skill: Dynamic Programming
Runtime: 626 ms, faster than 77.18% 
Memory Usage: 17 MB, less than 56.27%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= m, n <= 200
    0 <= matrix[i][j] <= 2^31 - 1
"""

from typing import List

class Solution:
    def longestIncreasingPath(self,matrix: List[List[int]]) -> int:
        dp = [[-1 for i in range(len(matrix[0]))] for j in range(len(matrix))]
        dir = [[0,1],[0,-1],[1,0],[-1,0]]
        res = 0
        
        def check_valid(x,y):
            if x>=0 and x<len(matrix) and y>=0 and y<len(matrix[0]):
                return True
            return False
        
        def bfs(i,j):
            if dp[i][j] == -1:
                l = 0
                for dirx, diry in dir:
                    if check_valid(i+dirx,j+diry) and matrix[i][j]<matrix[i+dirx][j+diry]:
                        l = max(l,bfs(i+dirx,j+diry))
                dp[i][j] = l+1
                        
            return dp[i][j]    
            
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                res = max(res, bfs(i,j))
        
        return res