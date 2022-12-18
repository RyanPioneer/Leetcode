"""
Source: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/
Date: 2022/12/15
Skill:
Runtime: 347 ms, faster than 91.26% 
Memory Usage: 18.1 MB, less than 83.8%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in each tree is in the range [0, 5000].
    -10^5 <= Node.val <= 10^5
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
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        stack1, stack2, res = [], [], []
        while root1:
            stack1.append(root1)
            root1 = root1.left
        while root2:
            stack2.append(root2)
            root2 = root2.left
        
        def helper(stack):
            if not stack: return None
            node = stack.pop()
            if node.right:
                root = node.right
                while root:
                    stack.append(root)
                    root = root.left
            return node
        
        node1, node2 = helper(stack1), helper(stack2)
        while node1 or node2:
            if node1 and node2:
                if node1.val <= node2.val:
                    res.append(node1.val)
                    node1 = helper(stack1)
                else:
                    res.append(node2.val)
                    node2 = helper(stack2)
            elif node1:
                while node1:
                    res.append(node1.val)
                    node1 = helper(stack1)
            else:
                while node2:
                    res.append(node2.val)
                    node2 = helper(stack2)
                    
        return res