"""
Source: https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/description/
Date: 2023/1/10
Skill:
Ref:
Runtime: 24 ms, faster than 100%
Memory Usage: 13.9 MB, less than 49%
Time complexity:
Space complexity:
Constraints:
    All the values in the tree are unique.
"""

from typing import List, Optional
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def flipMatchVoyage(self, root: Optional[TreeNode], voyage: List[int]) -> List[int]:
        res, index, stack = [], 0, [root]
        while stack:
            cur = stack.pop()
            if cur.val != voyage[index]: return [-1]
            if cur.left:
                if voyage[index+1] != cur.left.val:
                    if cur.right and cur.right.val == voyage[index + 1]:
                        res.append(cur.val)
                        stack.append(cur.left)
                        stack.append(cur.right)
                    else: return [-1]
                else:
                    if cur.right: stack.append(cur.right)
                    stack.append(cur.left)
            elif cur.right:
                stack.append(cur.right)

            index += 1

        return res