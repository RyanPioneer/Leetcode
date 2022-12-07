"""
Source: https://leetcode.com/problems/range-sum-of-bst/description/
Date: 2022/12/7
Skill: 
Runtime: 204 ms, faster than 98.68% 
Memory Usage: 23 MB, less than 50.66%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        self.res=0
        
        def pre_order(root):
            if root.val < low and root.right:
                pre_order(root.right)
            elif root.val >= low and root.val <= high:
                if root.left:
                     pre_order(root.left)
                self.res += root.val
                if root.right:
                    pre_order(root.right)
            else:
                if root.left:
                     pre_order(root.left)
        
        pre_order(root)
        return self.res
                