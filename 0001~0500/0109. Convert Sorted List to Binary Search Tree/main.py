"""
Source: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
Date: 2022/12/16
Skill: 
Runtime: 107 ms, faster than 100% 
Memory Usage: 20.3 MB, less than 30.38%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in head is in the range [0, 2 * 10^4].
    -10^5 <= Node.val <= 10^5
"""

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        arr = []
        while head:
            arr.append(head.val)
            head = head.next
        
        def helper(v):
            if not v:
                return None
            mid = len(v)//2
            return TreeNode(v[mid], helper(v[:mid]), helper(v[mid+1:]))
            
        return helper(arr)