"""
Source: https://rb.gy/0efsj
Date: 2023/7/22
Skill:
Ref:
Runtime: 71 ms, faster than 33.92%
Memory Usage: 17.14 MB, less than 15.20%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        def dfs(node):
            if not node:
                return None
            node.left = dfs(node.left)
            node.right = dfs(node.right)
            if not node.left and not node.right and node.val == target:
                return None
            return node

        return dfs(root)


if __name__ == "__main__":
    s = Solution()
