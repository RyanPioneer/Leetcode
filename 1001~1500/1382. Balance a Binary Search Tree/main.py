"""
Source: https://leetcode.com/problems/balance-a-binary-search-tree/description/
Date: 2022/12/15
Skill:
Runtime: 362 ms, faster than 91.13% 
Memory Usage: 21 MB, less than 47.72%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the tree is in the range [1, 10^4].
    1 <= Node.val <= 10^5
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
    def balanceBST(self, root: TreeNode) -> TreeNode:
        order = []
        
        def inorder(root):
            if root:
                inorder(root.left)
                order.append(root.val)
                inorder(root.right)
        
        inorder(root)
        
        def make_tree(order):
            if not order:
                return None
            mid = len(order)//2
            root = TreeNode(val=order[mid], left=make_tree(order[:mid]),\
                            right=make_tree(order[mid+1:]))
            return root
        
        return make_tree(order)