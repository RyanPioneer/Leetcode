"""
Source: https://leetcode.com/problems/balance-a-binary-search-tree/description/
Date: 2022/12/15
Skill:
Runtime: 328 ms, faster than 98.4% 
Memory Usage: 19.3 MB, less than 91%
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
        stack, nodes = [], []
        
        while root or stack:
            if root:
                while root:
                    stack.append(root)
                    root = root.left
            else:
                node = stack.pop()
                nodes.append(node)
                root = node.right
                
        def helper(nodes):
            if not nodes:
                return None
            mid = len(nodes)//2
            nodes[mid].left = helper(nodes[:mid])
            nodes[mid].right = helper(nodes[mid+1:])
            return nodes[mid]
        
        return helper(nodes)