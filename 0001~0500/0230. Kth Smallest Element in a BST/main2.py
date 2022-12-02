"""
Source: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
Date: 2022/11/30
Skill: Iterative, Stack
Runtime: 85 ms, faster than 70.81% 
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
        stack = []
        
        while True:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            k -= 1
            if not k:
                return root.val
            root = root.right
        
            