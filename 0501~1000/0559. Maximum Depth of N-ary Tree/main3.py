"""
Source: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
Date: 2022/12/2
Skill: BFS
Runtime: 98 ms, faster than 40.21%
Memory Usage: 16.1 MB, less than 53.12%
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
        queue = []
        if root: queue.append((root, 1))
        depth = 0
        for (node, level) in queue:
            depth = level
            queue += [(child, level+1) for child in node.children]
        return depth