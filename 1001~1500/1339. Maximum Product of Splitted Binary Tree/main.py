"""
Source: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
Date: 2022/12/10
Skill: 
Runtime: 382 ms, faster than 85.53% 
Memory Usage: 74.9 MB, less than 72.5%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the tree is in the range [2, 5 * 10^4].
    1 <= Node.val <= 10^4
"""

from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        self.res, sum = 0, 0
        stack = [root]
        while stack:
            cur = stack.pop()
            sum = (cur.val+sum)
            if cur.left:
                stack.append(cur.left)
            if cur.right:
                stack.append(cur.right)
                
        def findMaxProduct(root):
            if not root:
                return 0
            if not root.left and not root.right:
                return root.val
            left_sum = findMaxProduct(root.left)
            self.res = max(self.res, left_sum*(sum-left_sum))
            right_sum = findMaxProduct(root.right)
            self.res = max(self.res, right_sum*(sum-right_sum))
            return (left_sum+right_sum+root.val)
        
        findMaxProduct(root)
        return self.res%(pow(10,9)+7)