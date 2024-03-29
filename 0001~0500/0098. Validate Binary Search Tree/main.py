"""
Source: https://leetcode.com/problems/validate-binary-search-tree/
Date: 2023/1/27
Skill: 
Runtime: 56 ms, faster than 41.40%
Memory Usage: 16.2 MB, less than 99.34%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [1, 10^4].
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
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
        
        nums, cur, stack = [], root, []
        while cur:
            stack.append(cur)
            cur = cur.left
        
        while stack:
            cur = stack.pop()
            nums.append(cur.val)
            if cur.right:
                cur = cur.right
                while cur:
                    stack.append(cur)
                    cur = cur.left
        
        for i in range(len(nums)-1):
            if nums[i] >= nums[i+1]:
                return False
        
        return True