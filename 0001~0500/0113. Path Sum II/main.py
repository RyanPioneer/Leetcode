"""
Source: https://leetcode.com/problems/path-sum-ii/
Date: 2023/1/31
Skill:
Runtime: 46 ms, faster than 78.14%
Memory Usage: 15.6 MB, less than 50.92%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [0, 5000].
    -1000 <= Node.val <= 1000
    -1000 <= targetSum <= 1000
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        stack, res = [], []

        def dfs(node):
            if not node: return
            stack.append(node.val)
            if not node.left and not node.right:
                if sum(stack) == targetSum:
                    res.append(list(stack))
            else:
                if node.left:
                    dfs(node.left)
                if node.right:
                    dfs(node.right)
            stack.pop()
            return

        dfs(root)
        return res