"""
Source: https://leetcode.com/problems/reorder-list/
Date: 2023/3/18
Skill:
Runtime: 92 ms, faster than 62.33%
Memory Usage: 24 MB, less than 58.40%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the list is in the range [1, 5 * 10^4].
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head.next:
            return
        dummy_head = ListNode(0, head)
        fast, slow = dummy_head, dummy_head
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next

        cur, prev, fast = slow.next, None, head
        slow.next = None
        while cur.next:
            next = cur.next
            cur.next = prev
            prev = cur
            cur = next

        cur.next = prev

        while fast:
            tmp = fast.next
            tmp2 = cur.next
            fast.next = cur
            if tmp:
                cur.next = tmp
            fast = tmp
            cur = tmp2


if __name__ == "__main__":
    s = Solution()
