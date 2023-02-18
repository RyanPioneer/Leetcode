"""
Source: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
Date: 2023/2/17
Skill:
Runtime: 34 ms, faster than 62.82%
Memory Usage: 13.9 MB, less than 74.83%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [2, 100].
    0 <= Node.val <= 10^5
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
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        prev, stack, res = -math.inf, [], math.inf
        while root != None:
            stack.append(root)
            root = root.left

        while stack:
            node = stack.pop()
            res = min(res, node.val - prev)
            prev = node.val
            if node.right:
                node = node.right
                while node:
                    stack.append(node)
                    node = node.left

        return res


if __name__ == "__main__":
    s = Solution