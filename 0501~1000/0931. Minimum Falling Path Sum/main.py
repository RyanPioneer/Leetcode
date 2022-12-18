"""
Source: https://leetcode.com/problems/minimum-falling-path-sum/description/
Date: 2022/12/13
Skill: 
Runtime: 139 ms, faster than 92.88% 
Memory Usage: 14.7 MB, less than 91.12%
Time complexity: 
Space complexity: 
Constraints: 
    n == matrix.length == matrix[i].length
    1 <= n <= 100
    -100 <= matrix[i][j] <= 100
"""

from typing import List

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        sz = len(matrix)
        dp = [[matrix[0][i] for i in range(sz)] for j in range(2)]
        for i in range(1, sz):
            dp[i%2][0] = min(dp[(i-1)%2][0], dp[(i-1)%2][1])+matrix[i][0]
            for j in range(1, sz-1):
                dp[i%2][j] = min(dp[(i-1)%2][j-1], dp[(i-1)%2][j], dp[(i-1)%2][j+1])+matrix[i][j]
            dp[i%2][sz-1] = min(dp[(i-1)%2][sz-2], dp[(i-1)%2][sz-1])+matrix[i][sz-1]
        
        return min(dp[(sz-1)%2][i] for i in range(sz))