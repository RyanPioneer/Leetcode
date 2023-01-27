"""
Source: https://leetcode.com/problems/validate-binary-search-tree/
Date: 2023/1/27
Skill: 
Runtime: 29 ms, faster than 90.42%
Memory Usage: 13.8 MB, less than 66.28%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [1, 10^4].
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
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        