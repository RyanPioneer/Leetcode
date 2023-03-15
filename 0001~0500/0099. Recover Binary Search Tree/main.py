"""
Source: https://leetcode.com/problems/recover-binary-search-tree/
Date: 2023/3/15
Skill:
Runtime: 81 ms, faster than 30.10%
Memory Usage: 14.2 MB, less than 58.52%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [2, 1000].
    -2^31 <= Node.val <= 2^31 - 1
"""

import math
import random
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.last_node = TreeNode(val=-2**31-1)
        self.first, self.second, self.first_next = None, None, None

        def inorder(node):
            if not node:
                return
            inorder(node.left)
            if node.val <= self.last_node.val:
                if not self.first:
                    self.first = self.last_node
                    self.first_next = node
                else:
                    self.second = node
            self.last_node = node
            inorder(node.right)

        inorder(root)
        if not self.second:
            self.first.val, self.first_next.val = self.first_next.val, self.first.val
        else:
            self.first.val, self.second.val = self.second.val, self.first.val


# 1 2 3 4 5 6 7
# 1 5 3 4 2 6 7

# 1 2 3
# 3 2 1

if __name__ == "__main__":
    s = Solution()
    a = None
    a = TreeNode(val=2)
    print(a.val)
