"""
Source: https://leetcode.com/problems/insertion-sort-list/
Date: 2022/12/30
Skill:
Runtime: 1788 ms, faster than 37.63%
Memory Usage: 16.5 MB, less than 82.23%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the list is in the range [1, 5000].
    -5000 <= Node.val <= 5000
"""

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, cur = head, head.next
        dummy_node = ListNode(-5001, head)
        while cur:
            front = dummy_node
            while front.next != cur and front.next.val < cur.val:
                front = front.next
            if front.next != cur:
                prev.next = cur.next
                cur.next = front.next
                front.next = cur
                cur = prev.next
            else:
                prev = cur
                cur = cur.next

        return  dummy_node.next