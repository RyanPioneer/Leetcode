"""
Source: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
Date: 2022/12/9
Skill: 
Runtime: 79 ms, faster than 47.15% 
Memory Usage: 19.9 MB, less than 60.12%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the tree is in the range [2, 5000].
    0 <= Node.val <= 10^5
"""

from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        
        def post_order(root, low, high):
            if not root:
                return high - low
            high = max(high, root.val)
            low = min(low, root.val)
            return max(post_order(root.left, low, high), post_order(root.right, low, high))
        
        return post_order(root, root.val, root.val)