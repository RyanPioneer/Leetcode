"""
Source: https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/
Date: 2023/1/9
Skill:
Ref:
Runtime: 2065 ms, faster than 88.45%
Memory Usage: 166.5 MB, less than 30.33%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        edges, visited = defaultdict(list), set()
        for road in roads:
            edges[road[0]].append(road[1])
            edges[road[1]].append(road[0])

        def dfs(root):
            res, people = 0, 1
            visited.add(root)
            for n in edges[root]:
                if n not in visited:
                    next_res, next_people = dfs(n)
                    res += next_res + -(next_people // -seats)
                    people += next_people

            return res, people

        return dfs(0)[0]