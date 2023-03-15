"""
Source: https://leetcode.com/problems/recover-binary-search-tree/
Date: 2023/3/14
Skill:
Runtime: 944 ms, faster than 32.44%
Memory Usage: 53.2 MB, less than 72.53%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [2, 1000].
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


if __name__ == "__main__":
    s = Solution()
