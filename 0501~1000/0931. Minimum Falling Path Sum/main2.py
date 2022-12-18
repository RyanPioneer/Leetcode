"""
Source: https://leetcode.com/problems/minimum-falling-path-sum/description/
Date: 2022/12/13
Skill: 
Runtime: 266 ms, faster than 66.9% 
Memory Usage: 14.8 MB, less than 64.34%
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
        for i in range(1, len(matrix)):
            matrix[i][0] += min(matrix[(i-1)][0], matrix[i-1][1])
            for j in range(1, len(matrix)-1):
                matrix[i][j] += min(matrix[i-1][j-1], matrix[i-1][j], matrix[i-1][j+1])
            matrix[i][len(matrix)-1] += min(matrix[i-1][len(matrix)-2], matrix[i-1][len(matrix)-1])
        
        return min(matrix[len(matrix)-1][i] for i in range(len(matrix)))