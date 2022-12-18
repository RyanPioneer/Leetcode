"""
Source: https://leetcode.com/problems/leaf-similar-trees/
Date: 2022/12/8
Skill: 
Runtime: 54 ms, faster than 68.58% 
Memory Usage: 14 MB, less than 46.25%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in each tree will be in the range [1, 200].
"""

from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        
        def pre_order(root):
            ans = []
            if not root.left and not root.right:
                ans.append(root.val)
            if root.left:
                ans += pre_order(root.left)
            if root.right:
                ans += pre_order(root.right)
            return ans
    
        return pre_order(root1) == pre_order(root2)