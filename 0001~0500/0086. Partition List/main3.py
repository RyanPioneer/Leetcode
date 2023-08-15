"""
Source: https://leetcode.com/problems/partition-list/
Date: 2023/8/15
Skill:
Runtime: 45 ms, faster than 70.03%
Memory Usage: 16.14 MB, less than 98.91%
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
        dummy_head = ListNode(val=400, next=head)
        smaller, larger_or_equal = dummy_head, dummy_head
        while smaller.next and smaller.next.val < x:
            larger_or_equal = larger_or_equal.next
            smaller = smaller.next
        while larger_or_equal.next:
            while larger_or_equal.next and larger_or_equal.next.val >= x:
                larger_or_equal = larger_or_equal.next
            if larger_or_equal.next:
                tmp = larger_or_equal.next
                larger_or_equal.next = tmp.next
                tmp.next = smaller.next
                smaller.next = tmp
                smaller = tmp

        return dummy_head.next


if __name__ == "__main__":
    s = Solution()
