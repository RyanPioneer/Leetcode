"""
Source: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
Date: 2022/11/30
Skill: Recursive
Runtime: 89 ms, faster than 68.64%
Memory Usage: 18 MB, less than 46.88%
Time complexity: 
Space complexity: 
Constraints: 
    1 <= k <= n <= 10^4
"""

from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.res = 0
        self.k = k
        def inorder_traversal(node: Optional[TreeNode]):
            if node:
                inorder_traversal(node.left)
                self.k -= 1
                if self.k < 0:
                    return
                if self.k == 0:
                    self.res = node.val
                    return
                inorder_traversal(node.right)
        inorder_traversal(root)
        return self.res
            