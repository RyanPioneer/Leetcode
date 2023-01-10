"""
Source: https://leetcode.com/problems/binary-tree-preorder-traversal/
Date: 2023/1/9
Skill:
Ref:
Runtime: 28 ms, faster than 94.19%
Memory Usage: 13.7 MB, less than 96.79%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100
"""

from typing import List, Optional
import  math

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root: return []
        res, stack = [], [root]
        while stack:
            cur = stack.pop()
            res.append(cur.val)
            if cur.right: stack.append(cur.right)
            if cur.left: stack.append(cur.left)

        return res