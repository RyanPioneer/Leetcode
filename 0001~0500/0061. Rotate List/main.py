"""
Source: https://leetcode.com/problems/rotate-list/
Date: 2023/3/21
Skill:
Runtime: 47 ms, faster than 18.94%
Memory Usage: 13.9 MB, less than 68.68%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the list is in the range [0, 500].
    0 <= k <= 2 * 10^9
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
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not k:
            return head
        num, tail, node = 1, head, head
        while tail.next:
            tail = tail.next
            num += 1

        if k % num == 0:
            return head
        for _ in range(num - k % num - 1):
            node = node.next
        tail.next = head
        head = node.next
        node.next = None
        return head


if __name__ == "__main__":
    s = Solution()
