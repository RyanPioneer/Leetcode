"""
Source: https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/
Date: 2022/12/9
Skill: 
Runtime: 55 ms, faster than 90.75% 
Memory Usage: 16 MB, less than 85.84%
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
    def postorder(self, root: 'Node') -> List[int]:
        if not root:
            return None
        stack, res = [root], []
        while stack:
            cur_node = stack.pop()
            res.append(cur_node.val)
            if cur_node.children:
                for child in cur_node.children:
                    stack.append(child)
        return reversed(res)