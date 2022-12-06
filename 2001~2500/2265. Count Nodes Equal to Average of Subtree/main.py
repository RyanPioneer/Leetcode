"""
Source: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
Date: 2022/12/2
Skill: 
Runtime: 91 ms, faster than 59.12%
Memory Usage: 15.2 MB, less than 35.70%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the tree is in the range [1, 1000].
    0 <= Node.val <= 1000
"""

from typing import List, Optional
from collections import Counter

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        res = 0
        
        def post_order_trace(root):
            nonlocal res
            if not root:
                return 0, 0
            
            left_sum, left_count = post_order_trace(root.left)
            right_sum, right_count = post_order_trace(root.right)
            if (left_sum+right_sum+root.val)//(left_count+right_count+1) == root.val:
                res += 1
            return left_sum+right_sum+root.val, left_count+right_count+1
                
        post_order_trace(root)
        return res