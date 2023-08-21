"""
Source: https://rb.gy/yxjj1
Date: 2023/8/21
Skill:
Ref:
Runtime: 43 ms, faster than 98.80%
Memory Usage: 20.44 MB, less than 50.12%
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
from functools import cache


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def trimBST(self, root: Optional[TreeNode], low: int, high: int) -> Optional[TreeNode]:
        if not root:
            return None
        elif root.val < low:
            return self.trimBST(root.right, low, high)
        elif root.val > high:
            return self.trimBST(root.left, low, high)
        else:
            root.left = self.trimBST(root.left, low, root.val)
            root.right = self.trimBST(root.right, root.val, high)
            return root


if __name__ == "__main__":
    s = Solution()
