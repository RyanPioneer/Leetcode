"""
Source: https://leetcode.com/problems/binary-tree-postorder-traversal/description/
Date: 2022/12/9
Skill: 
Runtime: 50 ms, faster than 65.52% 
Memory Usage: 13.8 MB, less than 60.95%
Time complexity: 
Space complexity: 
Constraints: 
    The number of the nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100
"""

from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return None
        res, stack = [], [root]
        while stack:
            cur = stack.pop()
            res.append(cur.val)
            if cur.left:
                stack.append(cur.left)
            if cur.right:
                stack.append(cur.right)
        
        return reversed(res)