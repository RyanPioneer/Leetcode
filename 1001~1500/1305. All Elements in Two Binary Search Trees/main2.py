"""
Source: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/
Date: 2022/12/15
Skill:
Runtime: 337 ms, faster than 92.37% 
Memory Usage: 22.8 MB, less than 57.56%
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
            def inorder(node: TreeNode) -> None:
                if not node:
                    return
                inorder(node.left)
                ans.append(node.val)
                inorder(node.right)
            ans = []
            inorder(root1)
            inorder(root2)
            return sorted(ans)