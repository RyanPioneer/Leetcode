"""
Source: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
Date: 2022/12/8
Skill: 
Runtime: 1777 ms, faster than 97.39% 
Memory Usage: 60.6 MB, less than 40.91%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the list is in the range [1, 10^5].
"""

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head.next:
            return None
        dummyNode = ListNode(-1, head)
        fast = slow = dummyNode
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next
        slow.next = slow.next.next
        return head