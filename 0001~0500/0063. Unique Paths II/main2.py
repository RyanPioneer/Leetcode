"""
Source: https://leetcode.com/problems/unique-paths-ii/
Date: 2023/8/12
Skill: Dynamic Programming
Runtime: 44 ms, faster than 93.35%
Memory Usage: 16.32 MB, less than 82.98%
Time complexity:
Space complexity:
Constraints:
    1 <= grid.length, grid[i].length <= 100
"""

from typing import List, Optional


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        dp = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            if obstacleGrid[i][0] == 1:
                break
            dp[i][0] = 1
        for i in range(n):
            if obstacleGrid[0][i] == 1:
                break
            dp[0][i] = 1
        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] == 0:
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

        return dp[-1][-1]
