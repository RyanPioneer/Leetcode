"""
Source: https://leetcode.com/problems/delete-nodes-and-return-forest/
Date: 2022/12/12
Skill: 
Runtime: 63 ms, faster than 97.22% 
Memory Usage: 14.5 MB, less than 31.79%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the given tree is at most 1000.
    Each node has a distinct value between 1 and 1000.
    o_delete contains distinct values between 1 and 1000.
"""

from typing import List, Optional
from collections import defaultdict

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        self.res, to_delete = [], set(to_delete)
        
        def findNode(root):
            if root:
                if root.val not in to_delete:
                    self.res.append(root)
                    stack = [root]
                    while stack:
                        cur = stack.pop()
                        if cur.left:
                            if cur.left.val in to_delete:
                                findNode(cur.left.left)
                                findNode(cur.left.right)
                                cur.left = None
                            else:
                                stack.append(cur.left)
                        if cur.right:
                            if cur.right.val in to_delete:
                                findNode(cur.right.left)
                                findNode(cur.right.right)
                                cur.right = None
                            else:
                                stack.append(cur.right)
                else:
                    findNode(root.left)
                    findNode(root.right)
        
        findNode(root)
        return self.res