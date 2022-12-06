"""
Source: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
Date: 2022/12/2
Skill: DFS
Runtime: 51 ms, faster than 87.97%
Memory Usage: 15.9 MB, less than 94.37%
Time complexity: 
Space complexity: 
Constraints: 
    The total number of nodes is in the range [0, 104].
    The depth of the n-ary tree is less than or equal to 1000.
"""

# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution(object):
    def maxDepth(self, root):
        stack = []
        if root: stack.append((root, 1))
        depth = 0
        while stack:
            (node, d) = stack.pop()
            depth = max(depth, d)
            for child in node.children:
                stack.append((child, d+1))
        return depth