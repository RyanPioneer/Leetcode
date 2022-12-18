"""
Source: https://leetcode.com/problems/delete-nodes-and-return-forest/
Date: 2022/12/12
Skill: 
Runtime: 70 ms, faster than 89.79% 
Memory Usage: 14.4 MB, less than 97.22%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the given tree is at most 1000.
    Each node has a distinct value between 1 and 1000.
    o_delete contains distinct values between 1 and 1000.
"""

from typing import List, Optional
from collections import Counter

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        hashTable = Counter(to_delete)
        res = []
        
        def helper(root, isRoot):
            if not root:
                return None
            if hashTable[root.val]:
                helper(root.left, True)
                helper(root.right, True)
                return None
            if isRoot:
                res.append(root)
            root.left = helper(root.left, False)
            root.right = helper(root.right, False)
            return root
        
        helper(root, True)
        return res