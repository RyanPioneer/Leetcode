"""
Source: https://leetcode.com/problems/longest-univalue-path/description/
Date: 2022/12/11
Skill: 
Runtime: 388 ms, faster than 90.91% 
Memory Usage: 18.1 MB, less than 36.23%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the tree is in the range [0, 10^4].
    -1000 <= Node.val <= 1000
    The depth of the tree will not exceed 1000.
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
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        res = 0
        def dfs(root):
            nonlocal res
            if not root:
                return 0
            left_num, right_num = dfs(root.left), dfs(root.right)
            left_num = left_num+1 if root.left and root.val == root.left.val else 0
            right_num = right_num+1 if root.right and root.val == root.right.val else 0
            res = max(res, left_num+right_num)
            return max(left_num, right_num)
        
        _ = dfs(root)
        return res