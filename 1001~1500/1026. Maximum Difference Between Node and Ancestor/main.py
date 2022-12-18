"""
Source: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
Date: 2022/12/9
Skill: 
Runtime: 91 ms, faster than 19.98% 
Memory Usage: 20.3 MB, less than 13.84%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the tree is in the range [2, 5000].
    0 <= Node.val <= 10^5
"""

from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        
        def post_order(root):
            left_max, left_min, left_ans, right_max, right_min, right_ans\
                = root.val, root.val, 0, root.val, root.val, 0
            if root.left:
                left_max, left_min, left_ans = post_order(root.left)
            if root.right:
                right_max, right_min, right_ans = post_order(root.right)
            cur_max, cur_min, cur_ans = max(left_max, right_max, root.val), min(left_min, right_min, root.val), max(left_ans, right_ans)
            return cur_max, cur_min, max(cur_ans, abs(root.val-cur_max), abs(root.val-cur_min))
        
        max_value, min_value, ans = post_order(root)
        return ans