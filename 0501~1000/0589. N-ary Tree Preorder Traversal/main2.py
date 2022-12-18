"""
Source: https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/
Date: 2022/12/9
Skill: 
Runtime: 111 ms, faster than 41.74% 
Memory Usage: 16 MB, less than 81.81%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the tree is in the range [0, 10^4].
    0 <= Node.val <= 10^4
    The height of the n-ary tree is less than or equal to 1000.
"""

from typing import List, Optional

# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        if not root:
            return []
        stack = [root]
        result = []
        while stack:
            top = stack.pop()
            result.append(top.val)
            stack.extend(reversed(top.children))
        return result