"""
Source: https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/
Date: 2022/11/21
Skill: bisect_left(nums, q)
Runtime: 1847 ms, faster than 100.00%
Memory Usage: 157.6 MB, less than 14.29%
Time complexity: 
Space complexity: 
Constraints: 
    
"""

from typing import List, Optional
from bisect import bisect, bisect_left

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def closestNodes(self, root: Optional[TreeNode], queries: List[int]) -> List[List[int]]:
        def dfs(n,v):
            if n: 
                dfs(n.left,v)
                v.append(n.val)
                dfs(n.right,v)
        
        res, nums = [], []
        dfs(root,nums)    
        for q in queries:
            i = bisect_left(nums,q)
            if i < len(nums) and nums[i] == q:
                res.append([q,q])
            else:
                if i == 0: res.append([-1,nums[0]])
                elif i == len(nums): res.append([nums[len(nums)-1],-1])
                else: res.append([nums[i-1],nums[i]])
        
        return res