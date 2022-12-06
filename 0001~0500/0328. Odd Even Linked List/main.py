"""
Source: https://leetcode.com/problems/odd-even-linked-list/
Date: 2022/12/6
Skill: 
Runtime: 45 ms Beats 92.97%
Memory Usage: 16.6 MB Beats 31.2%
Time complexity: 
Space complexity: 
Constraints: 
    The number of nodes in the linked list is in the range [0, 10^4].
    -10^6 <= Node.val <= 10^6
"""

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head and head.next:
            odd, even, even_head = head, head.next, head.next
            while even.next:
                odd.next = even.next
                odd = odd.next
                if odd.next:
                    even.next = odd.next
                    even = even.next
                else:
                    even.next = None
            odd.next = even_head
        return head