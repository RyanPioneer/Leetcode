"""
Source: https://leetcode.com/problems/invert-binary-tree/description/
Date: 2023/2/18
Skill:
Runtime: 34 ms, faster than 59.87%
Memory Usage: 13.8 MB, less than 94.98%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [0, 100].
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
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root:
            root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)
        return root


if __name__ == "__main__":
    s = Solution