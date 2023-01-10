"""
Source: https://leetcode.com/problems/same-tree/
Date: 2023/1/10
Skill:
Ref:
Runtime: 35 ms, faster than 73.56%
Memory Usage: 13.8 MB, less than 72.95%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in both trees is in the range [0, 100].
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
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p == None and q == None : return True
        if p == None or q == None : return False
        que = deque()
        que.append(p)
        que.append(q)
        while que:
            cur1 = que.popleft()
            if not que: return False
            cur2 = que.popleft()
            if cur1.val != cur2.val: return False
            if cur1.left:
                if not cur2.left: return False
                que.append(cur1.left)
                que.append(cur2.left)
            elif cur2.left: return False
            if cur1.right:
                if not cur2.right: return False
                que.append(cur1.right)
                que.append(cur2.right)
            elif cur2.right: return False

        return True