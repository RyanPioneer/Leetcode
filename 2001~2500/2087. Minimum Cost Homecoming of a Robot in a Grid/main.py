"""
Source: https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/
Date: 2022/12/31
Skill:
Runtime: 1445 ms, faster than 95.12%
Memory Usage: 28.3 MB, less than 97.56%
Time complexity:
Space complexity:
Constraints:
    1 <= grid.length, grid[i].length <= 10^5
"""

from typing import List, Optional

class Solution:
    def minCost(self, startPos: List[int], homePos: List[int], rowCosts: List[int], colCosts: List[int]) -> int:
        r_dir, c_dir, cost = 1 if homePos[0] > startPos[0] else -1, 1 if homePos[1] > startPos[1] else -1, 0
        while startPos[0] != homePos[0]:
            startPos[0] += r_dir
            cost += rowCosts[startPos[0]]

        while startPos[1] != homePos[1]:
            startPos[1] += c_dir
            cost += colCosts[startPos[1]]

        return cost