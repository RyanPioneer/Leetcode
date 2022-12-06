"""
Source: https://leetcode.com/problems/middle-of-the-linked-list/
Date: 2022/12/5
Skill: Slow and Fast Pointers
Runtime: 48 ms, faster than 69.80% 
Memory Usage: 13.8 MB, less than 55.96%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the list is in the range [1, 100].
    1 <= Node.val <= 100
"""

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head
        while head.next and head.next.next:
            head = head.next.next
            slow = slow.next
        if head.next:
            return slow.next
        return slow