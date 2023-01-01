"""
Source: https://leetcode.com/problems/unique-paths-ii/
Date: 2022/12/31
Skill: Dynamic Programming
Runtime: 39 ms, faster than 96.31%
Memory Usage: 13.9 MB, less than 97.57%
Time complexity:
Space complexity:
Constraints:
    1 <= grid.length, grid[i].length <= 100
"""

from typing import List, Optional

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        dp = [[0 for _ in range(len(obstacleGrid[0]))] for _ in range(len(obstacleGrid))]

        for i in range(len(obstacleGrid)):
            if obstacleGrid[i][0]:
                break
            else:
                dp[i][0] = 1

        for i in range(len(obstacleGrid[0])):
            if obstacleGrid[0][i]:
                break
            else:
                dp[0][i] = 1

        for i in range(1, len(obstacleGrid)):
            for j in range(1, len(obstacleGrid[0])):
                if not obstacleGrid[i][j]:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]

        return dp[len(obstacleGrid)-1][len(obstacleGrid[0])-1]