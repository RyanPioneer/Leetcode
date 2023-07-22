"""
Source: https://rb.gy/0efsj
Date: 2023/7/22
Skill:
Ref:
Runtime: 77 ms, faster than 11.45%
Memory Usage: 17.06 MB, less than 53.52%
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
        dummy_root = TreeNode(left=root)
        stack = [(root, dummy_root, 0)]
        while stack:
            cur_node, cur_par, num = stack.pop()
            if num == 0:
                stack.append((cur_node, cur_par, 1))
                if cur_node.left:
                    stack.append((cur_node.left, cur_node, 0))
                if cur_node.right:
                    stack.append((cur_node.right, cur_node, 0))
            else:
                if cur_node.val == target and cur_node.left is None and cur_node.right is None:
                    if cur_par.left == cur_node:
                        cur_par.left = None
                    else:
                        cur_par.right = None

        return dummy_root.left


if __name__ == "__main__":
    s = Solution()
