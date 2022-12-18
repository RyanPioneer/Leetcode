"""
Source: https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
Date: 2022/12/11
Skill: 
Runtime: 49 ms, faster than 70.57% 
Memory Usage: 13.9 MB, less than 68.6%
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
        sum = 0
        def dfs(root, path):
            nonlocal sum
            if not root.left and not root.right:
                sum += int(path+str(root.val))
            else:
                if root.left:
                    dfs(root.left, path+str(root.val))
                if root.right:
                    dfs(root.right, path+str(root.val))
        
        dfs(root, '')
        return sum