"""
Source: https://rb.gy/vwg1d
Date: 2023/8/4
Skill:
Ref:
Runtime: 584 ms, faster than 91.84%
Memory Usage: 161.2 MB, less than 20.82%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        neighbors, visited = defaultdict(list), defaultdict(int)

        def dfs(node):
            if node.left:
                neighbors[node.val].append(node.left.val)
                neighbors[node.left.val].append(node.val)
                dfs(node.left)
            if node.right:
                neighbors[node.val].append(node.right.val)
                neighbors[node.right.val].append(node.val)
                dfs(node.right)

        dfs(root)
        q, res = deque([start]), -1
        visited[start] = 1
        while q:
            res += 1
            num = len(q)
            for _ in range(num):
                node = q.popleft()
                for neighbor in neighbors[node]:
                    if neighbor not in visited:
                        visited[neighbor] = 1
                        q.append(neighbor)

        return res


if __name__ == "__main__":
    s = Solution()
