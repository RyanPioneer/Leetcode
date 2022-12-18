"""
Source: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
Date: 2022/12/11
Skill: 
Runtime: 127 ms, faster than 72.72% 
Memory Usage: 19.5 MB, less than 99.96%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the tree is in the range [1, 3 * 10^4].
    -1000 <= Node.val <= 1000
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
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        stack, res = [[root, 0]], []
        while stack:
            cur = stack[-1][0]
            if cur == None:
                stack.pop()
                res.append([-math.inf, -math.inf])
                continue
            stack[-1][1] += 1
            if stack[-1][1] == 1:
                stack.append([cur.left, 0])
            elif stack[-1][1] == 2:
                stack.append([cur.right, 0])
            else:
                cur_r, no_cur_r = res.pop()
                cur_l, no_cur_l = res.pop()
                res.append([max(cur.val, cur.val+cur_r, cur.val+cur_l),\
                    max(cur.val, cur.val+cur_r, cur.val+cur_l, cur.val+cur_l+cur_r,no_cur_r, no_cur_l, cur_r, cur_l)])
                stack.pop()
            
        return max(res.pop())