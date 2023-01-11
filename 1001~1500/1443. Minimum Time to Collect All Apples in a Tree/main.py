"""
Source: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
Date: 2023/1/11
Skill:
Ref:
Runtime: 671 ms, faster than 94.87%
Memory Usage: 50.9 MB, less than 74.36%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [1, 2^14].
"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        neighbors, self.res = defaultdict(list), 0

        for edge in edges:
            neighbors[edge[0]].append(edge[1])
            neighbors[edge[1]].append(edge[0])

        def dfs(root, parent):
            apple = False
            if hasApple[root]: apple = True
            for child in neighbors[root]:
                if child != parent:
                    if dfs(child, root):
                        apple = True
                        self.res += 2

            return apple

        dfs(0, -1)
        return self.res

