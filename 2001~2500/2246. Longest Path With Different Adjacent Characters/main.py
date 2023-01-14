"""
Source: https://leetcode.com/problems/longest-path-with-different-adjacent-characters/
Date: 2023/1/13
Skill:
Ref:
Runtime: 1682 ms, faster than 91.9%
Memory Usage: 153 MB, less than 45.75%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List
from collections import defaultdict

class Solution:
    def longestPath(self, parent: List[int], s: str) -> int:
        graph, sz, self.res = defaultdict(list), len(parent), 0
        for i in range(1, sz):
            graph[parent[i]].append(i)

        def dfs(root) -> int:
            root_is_center, root_is_end = 1, 1
            first, second = 0, 0
            for child in graph[root]:
                child_is_end = dfs(child)
                if s[root] != s[child]:
                    if child_is_end > first:
                        second = first
                        first = child_is_end
                    elif child_is_end > second: second = child_is_end

            self.res = max(self.res, first+second+1)
            return first+1

        dfs(0)
        return self.res