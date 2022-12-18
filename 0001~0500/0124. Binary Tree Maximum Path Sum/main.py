"""
Source: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
Date: 2022/12/11
Skill: 
Runtime: 127 ms, faster than 72.72% 
Memory Usage: 21.7 MB, less than 10.62%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the tree is in the range [1, 3 * 10^4].
    -1000 <= Node.val <= 1000
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
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.res = -math.inf
        def dfs(root):
            if not root:
                return 0
            left_num, right_num = dfs(root.left), dfs(root.right)
            value1 = left_num+root.val+right_num
            value2 = left_num+root.val
            value3 = root.val+right_num
            self.res = max(self.res, value1, value2, value3, root.val)
            return max(value2, value3, root.val)
        
        dfs(root)
        return self.res