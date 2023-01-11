"""
Source: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/
Date: 2023/1/10
Skill:
Ref:
Runtime: 24 ms, faster than 100%
Memory Usage: 13.9 MB, less than 49%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [1, 2^14].
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
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        level, stack = 0, [root]
        while 1:
            if stack[-1].left != None:
                sz, nums = len(stack), []
                for i in range(sz):
