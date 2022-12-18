"""
Source: https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
Date: 2022/12/11
Skill: 
Runtime: 58 ms, faster than 49.5% 
Memory Usage: 13.8 MB, less than 98%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the tree is in the range [1, 1000].
    0 <= Node.val <= 9
"""

from typing import List, Optional
import math

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        stack, res = [[root, 0]], 0
        while stack:
            cur, num = stack.pop()
            if not cur.left and not cur.right:
                res += (num*10+cur.val)
                continue
            if  cur.left:
                stack.append([cur.left, num*10+cur.val])
            if cur.right:
                stack.append([cur.right, num*10+cur.val])
        return res