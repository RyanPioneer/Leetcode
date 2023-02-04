"""
Source: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
Date: 2023/2/1
Skill:
Runtime: 19 ms, faster than 99.93%
Memory Usage: 14.2 MB, less than 50.48%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [0, 2000].
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
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root: return []
        res, q, di = [], deque([root]), 0
        while q:
            di = (di+1)%2
            sz, level = len(q), []
            for _ in range(sz):
                if di:
                    cur = q.popleft()
                else:
                    cur = q.pop()
                level.append(cur.val)
                if not di:
                    cur.left, cur.right = cur.right, cur.left
                if cur.left:
                    if di: q.append(cur.left)
                    else: q.appendleft(cur.left)
                if cur.right:
                    if di: q.append(cur.right)
                    else: q.appendleft(cur.right)
            res.append(level)

        return res