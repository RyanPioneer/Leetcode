"""
Source: https://leetcode.com/problems/partition-list/
Date: 2023/8/15
Skill:
Runtime: 39 ms, faster than 90.41%
Memory Usage: 16.41 MB, less than 14.86%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the list is in the range [0, 200].
"""

import math
import random
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        less, greater_or_equal, node = deque(), deque(), head
        while node:
            if node.val < x:
                less.append(node.val)
            else:
                greater_or_equal.append(node.val)
            node = node.next
        node = head
        while node:
            if less:
                node.val = less.popleft()
            else:
                node.val = greater_or_equal.popleft()
            node = node.next
        return head


if __name__ == "__main__":
    s = Solution()
