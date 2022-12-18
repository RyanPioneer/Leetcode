"""
Source: https://leetcode.com/problems/insert-into-a-binary-search-tree/
Date: 2022/12/9
Skill: 
Runtime: 142 ms, faster than 88.1% 
Memory Usage: 16.9 MB, less than 90.79%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the tree will be in the range [0, 10^4].
    All the values Node.val are unique.
    It's guaranteed that val does not exist in the original BST.
"""

from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if not root:
            return TreeNode(val)
        cur = root
        while 1:
            if val < cur.val:
                if cur.left:
                    cur = cur.left
                else:
                    cur.left = TreeNode(val)
                    return root
            else:
                if cur.right:
                    cur = cur.right
                else:
                    cur.right = TreeNode(val)
                    return root