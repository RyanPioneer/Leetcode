"""
Source: https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/
Date: 2022/12/31
Skill: Dynamic Programming
Runtime: 2490 ms, faster than 96.79%
Memory Usage: 144.6 MB, less than 25.72%
Time complexity:
Space complexity:
Constraints:
    1 <= grid.length, grid[i].length <= 5*10^4
    1 <= k <= 50
"""

from typing import List, Optional

# With Row swapping DP, we can solve it with O(2 * N * K) memory.

class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        dp = [[[0 for _ in range(k)] for _ in range(len(grid[0]))] for _ in range(len(grid))]
        dp[0][0][grid[0][0]%k] = 1
        sum = grid[0][0]
        for i in range(1, len(grid[0])):
            sum += grid[0][i]
            dp[0][i][sum%k] = 1
        sum = grid[0][0]
        for i in range(1, len(grid)):
            sum += grid[i][0]
            dp[i][0][sum % k] = 1

        for i in range(1, len(grid)):
            for j in range(1, len(grid[0])):
                for l in range(k):
                    dp[i][j][(l+grid[i][j]) % k] = dp[i-1][j][l]+dp[i][j-1][l]

        return dp[len(grid)-1][len(grid[0])-1][0]%(pow(10, 9)+7)