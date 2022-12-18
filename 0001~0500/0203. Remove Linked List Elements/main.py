"""
Source: https://leetcode.com/problems/remove-linked-list-elements/description/
Date: 2022/12/8
Skill: 
Runtime: 129 ms, faster than 63.99% 
Memory Usage: 17.8 MB, less than 83.86%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the list is in the range [0, 10^4].
"""

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        while head and head.val == val:
            head = head.next
        
        tmp = head
        while tmp and tmp.next:
            if tmp.next.val == val:
                tmp.next = tmp.next.next
            else:
                tmp = tmp.next
                
        return head