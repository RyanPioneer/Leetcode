"""
Source: https://leetcode.com/problems/path-sum-iii/
Date: 2023/1/31
Skill: Prefix Sum + DFS
Runtime: 46 ms, faster than 95.33%
Memory Usage: 15.4 MB, less than 56.86%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [0, 1000].
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
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
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        my_dict, self.local_sum, self.res = defaultdict(int), 0, 0
        my_dict[0] = 1

        def helper(node):
            if node:
                self.local_sum += node.val
                self.res += my_dict[self.local_sum-targetSum]
                my_dict[self.local_sum] += 1
                helper(node.left)
                helper(node.right)
                my_dict[self.local_sum] -= 1
                self.local_sum -= node.val

        helper(root)
        return self.res

