"""
Source: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
Date: 2022/12/2
Skill: BFS
Runtime: 191 ms, faster than 5.14%
Memory Usage: 16.3 MB, less than 6.78%
Time complexity: 
Space complexity: 
Constraints: 
    The total number of nodes is in the range [0, 104].
    The depth of the n-ary tree is less than or equal to 1000.
"""

import queue


# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root:
            return 0
        q = queue.Queue()
        q.put(root)
        res = 0
        while not q.empty():
            res += 1
            sz = q.qsize()
            for i in range(sz):
                node = q.get()
                if node.children:
                    for child in node.children:
                        q.put(child)
        return res