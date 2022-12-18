"""
Source: https://leetcode.com/problems/longest-univalue-path/description/
Date: 2022/12/11
Skill: 
Runtime: 654 ms, faster than 68.31% 
Memory Usage: 17.5 MB, less than 99.73%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the tree is in the range [0, 10^4].
    -1000 <= Node.val <= 1000
    The depth of the tree will not exceed 1000.
"""

from typing import List, Optional
import math

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        stack, res = [[root, 0]], []
        while stack:
            cur = stack[-1][0]
            if not cur:
                res.append([0, 0])
                stack.pop()
                continue
            stack[-1][1] += 1
            if stack[-1][1] == 1:
                stack.append([cur.left, 0])
            elif stack[-1][1] == 2:  
                stack.append([cur.right, 0])      
            else:
                cur_r, no_cur_r = res.pop()
                cur_l, no_cur_l = res.pop()
                if cur.right and cur.val == cur.right.val and cur.left and cur.val == cur.left.val:
                    res.append([max(cur_r+1, cur_l+1), max(cur_r+cur_l+2, no_cur_r, no_cur_l)])
                elif cur.left and cur.val == cur.left.val:
                    res.append([cur_l+1, max(cur_l+1, no_cur_r, no_cur_l)])
                elif cur.right and cur.val == cur.right.val:
                    res.append([cur_r+1, max(cur_r+1, no_cur_r, no_cur_l)])
                else:
                    res.append([0, max(no_cur_r, no_cur_l)])
                stack.pop()
        
        return max(res.pop())