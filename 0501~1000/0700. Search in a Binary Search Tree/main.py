"""
Source: https://leetcode.com/problems/search-in-a-binary-search-tree/description/
Date: 2022/12/9
Skill: 
Runtime: 76 ms, faster than 95.96% 
Memory Usage: 16.6 MB, less than 25.5%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the tree is in the range [1, 5000].
    1 <= Node.val <= 10^7
"""

from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        while root:
            if root.val == val:
                return root
            elif root.val > val:
                root = root.left
            else:
                root = root.right