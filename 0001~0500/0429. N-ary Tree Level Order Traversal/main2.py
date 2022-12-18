"""
Source: https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
Date: 2022/12/9
Skill: 
Runtime: 52 ms, faster than 94.2% 
Memory Usage: 16 MB, less than 51.53%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List
from collections import deque 

# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def __init__(self):
        self.output = []

    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if root is None:
            return
        
        stack = deque()
        stack.append(root)
        output = [[root.val]]
        
        while stack:
            stack_len = len(stack)
            level = []
            for _ in range(stack_len):   
                curr_node = stack.popleft()
                if curr_node.children:
                    for child in curr_node.children:
                        level.append(child.val)
                        stack.append(child)

            if level:
                output.append(level)
        
        return output