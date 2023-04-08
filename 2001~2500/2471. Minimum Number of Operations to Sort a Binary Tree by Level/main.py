"""
Source: https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/
Date: 2023/4/8
Skill: index sort
Ref:
Runtime: 32 ms, faster than 94.54%
Memory Usage: 14.3 MB, less than 65.43%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [1, 10^5].
    All the values of the tree are unique.
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
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
    def minimumOperations(self, root: Optional[TreeNode]) -> int:



if __name__ == "__main__":
    s = Solution()
