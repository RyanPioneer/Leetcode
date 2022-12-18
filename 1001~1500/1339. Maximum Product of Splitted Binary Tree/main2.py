"""
Source: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
Date: 2022/12/10
Skill: 
Runtime: 320 ms, faster than 96.82% 
Memory Usage: 73.4 MB, less than 99.5%
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
        def helper(root):
            if not root:
                return 0
            root.val += (helper(root.left)+helper(root.right))
            return root.val
        
        _ = helper(root)
        cur, res, sum = root, 0, root.val
        while cur and cur.val >= sum//2:
            res = max(res, cur.val*(sum-cur.val))
            left_sum, right_sum = 0, 0
            if cur.left:
                left_sum = cur.left.val
            if cur.right:
                right_sum = cur.right.val
            if left_sum >= right_sum:
                cur = cur.left
            else:
                cur = cur.right
        
        if cur is None:
            return res % (pow(10, 9)+7)
        return max(res, cur.val*(sum-cur.val)) % (pow(10, 9)+7)