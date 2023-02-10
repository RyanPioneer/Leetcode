"""
Source: https://leetcode.com/problems/reverse-linked-list-ii/
Date: 2023/2/10
Skill:
Runtime: 30 ms, faster than 85.75%
Memory Usage: 14 MB, less than 44.46%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 500
    1 <= left <= right <= n
"""

from typing import List, Optional
from collections import defaultdict

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if left == right: return head
        dummy_head = ListNode(next=head)
        cur = dummy_head
        for _ in range(left-1):
            cur = cur.next
        first_tail, second_tail, prev, cur, next = cur, cur.next, None, cur.next, cur.next.next
        for _ in range(right-left):
            cur.next = prev
            prev = cur
            cur = next
            next = cur.next

        cur.next = prev
        first_tail.next = cur
        second_tail.next = next
        return dummy_head.next


if __name__ == "__main__":
    s = Solution