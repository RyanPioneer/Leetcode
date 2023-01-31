"""
Source: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
Date: 2023/1/31
Skill:
Runtime: 37 ms, faster than 82.80%
Memory Usage: 14.2 MB, less than 97.98%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [1, 500].
    All the values Node.val are unique.
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        parent, visited, res = defaultdict(), set(), []

        def find_target(node):
            if node == target: return
            if node.left:
                parent[node.left.val] = node
                find_target(node.left)
            if node.right:
                parent[node.right.val] = node
                find_target(node.right)

        find_target(root)

        def find_k(node, dis):
            visited.add(node.val)
            if dis == k:
                res.append(node.val)
                return
            if node.left and node.left.val not in visited:
                find_k(node.left, dis+1)
            if node.right and node.right.val not in visited:
                find_k(node.right, dis+1)
            if node.val in parent and parent[node.val].val not in visited:
                find_k(parent[node.val], dis+1)

        find_k(target, 0)
        return res