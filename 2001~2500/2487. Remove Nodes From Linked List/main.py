"""
Source: https://leetcode.com/problems/remove-nodes-from-linked-list/description/
Date: 2022/12/8
Skill: 
Runtime: 2703 ms, faster than 62.29% 
Memory Usage: 157.7 MB, less than 15.96%
Time complexity: 
Space complexity: 
Constraints: 
    The number of the nodes in the given list is in the range [1, 10^5].
"""

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        head.next = self.removeNodes(head.next)
        if head.next and head.val < head.next.val:
            return head.next
        else:
            return head