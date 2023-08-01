"""
Source: https://rb.gy/ueodl
Date: 2023/7/31
Skill:
Ref:
Runtime: 106 ms, faster than 93.14%
Memory Usage: 20.06 MB, less than 73.22%
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
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        res = 0

        def dfs(node, now, child):
            if not node:
                return
            nonlocal res
            if now:
                res += node.val
            if node.val % 2 == 0:
                grandchild = True
            else:
                grandchild = False
            dfs(node.left, child, grandchild)
            dfs(node.right, child, grandchild)

        dfs(root, False, False)
        return res


if __name__ == "__main__":
    s = Solution()
