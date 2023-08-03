"""
Source: https://rb.gy/ceh1e
Date: 2023/8/3
Skill:
Ref:
Runtime: 43 ms, faster than 81.54%
Memory Usage: 16.16 MB, less than 98.94%
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
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        if not root.left and not root.right:
            return [str(root.val)]
        res = []
        if root.left:
            for tree in self.binaryTreePaths(root.left):
                tree = str(root.val) + "->" + tree
                res.append(tree)
        if root.right:
            for tree in self.binaryTreePaths(root.right):
                tree = str(root.val) + "->" + tree
                res.append(tree)

        return res


if __name__ == "__main__":
    s = Solution()
