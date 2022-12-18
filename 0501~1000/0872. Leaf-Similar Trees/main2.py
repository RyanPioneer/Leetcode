"""
Source: https://leetcode.com/problems/leaf-similar-trees/
Date: 2022/12/8
Skill: 
Runtime: 60 ms, faster than 55.14% 
Memory Usage: 13.9 MB, less than 87.58%
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
        root1_seq, root2_seq = [], []
        
        def pre_order(root, ans):
            if not root.left and not root.right:
                ans.append(root.val)
            if root.left:
                pre_order(root.left, ans)
            if root.right:
                pre_order(root.right, ans)
    
        pre_order(root1, root1_seq)
        pre_order(root2, root2_seq)
        return root1_seq == root2_seq