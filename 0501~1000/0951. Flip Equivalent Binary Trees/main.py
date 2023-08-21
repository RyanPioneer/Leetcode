"""
Source: https://rb.gy/7tqqo
Date: 2023/8/21
Skill:
Ref:
Runtime: 33 ms, faster than 94.91%
Memory Usage: 16.37 MB, less than 57.89%
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
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        if not root1 and not root2:
            return True
        elif not root1 or not root2:
            return False
        elif root1.val != root2.val:
            return False
        else:
            return (self.flipEquiv(root1.left, root2.left) and self.flipEquiv(root1.right, root2.right)) \
                    or (self.flipEquiv(root1.left, root2.right) and self.flipEquiv(root1.right, root2.left))



if __name__ == "__main__":
    s = Solution()

