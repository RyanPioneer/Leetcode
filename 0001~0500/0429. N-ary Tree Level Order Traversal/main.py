"""
Source: https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
Date: 2022/12/9
Skill: 
Runtime: 143 ms, faster than 6.2% 
Memory Usage: 16.2 MB, less than 12.88%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List
import queue

# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:
            return None
        res, local_res = [], []
        q = queue.Queue()
        q.put(root)
        sz = 1
        while not q.empty():
            cur = q.get()
            local_res.append(cur.val)
            for child in cur.children:
                q.put(child)
            sz -= 1
            if sz == 0:
                sz = q.qsize()
                res.append(local_res)
                local_res = []
        
        return res