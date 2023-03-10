"""
Source: https://leetcode.com/problems/linked-list-cycle-ii/
Date: 2023/3/10
Skill:
Runtime: 48 ms, faster than 86.28%
Memory Usage: 17.3 MB, less than 52.59%
Time complexity:
Space complexity:
Constraints:
    The number of the nodes in the list is in the range [0, 10^4].
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast, slow = head, head
        while fast:
            if not fast.next or not fast.next.next:
                return None
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                break

        fast = head
        while fast != slow:
            fast = fast.next
            slow = slow.next

        return fast


if __name__ == "__main__":
    s = Solution()
