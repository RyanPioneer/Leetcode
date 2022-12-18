"""
Source: https://leetcode.com/problems/house-robber-iii/
Date: 2022/12/15
Skill:
Runtime: 49 ms, faster than 96.20% 
Memory Usage: 16 MB, less than 95.37%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the tree is in the range [1, 10^4].
    0 <= Node.val <= 10^4
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
    def rob(self, root: Optional[TreeNode]) -> int:
        def helper(root):
            if not root:
                return 0, 0
            left = helper(root.left)
            right = helper(root.right)
            return root.val+left[1]+right[1], max(left[0], left[1])+max(right[0], right[1])
        
        return max(helper(root))