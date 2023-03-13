"""
Source: https://leetcode.com/problems/partition-list/
Date: 2023/3/13
Skill:
Runtime: 41 ms, faster than 34.65%
Memory Usage: 13.8 MB, less than 67.72%
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
        dummy_node = ListNode(next=head)
        head1, head2 = dummy_node, dummy_node
        while head1.next and head1.next.val < x:
            head1 = head1.next
            head2 = head2.next

        while head2.next:
            while head2.next and head2.next.val >= x:
                head2 = head2.next
            if head2.next:
                cur_node = head2.next
                head2.next = cur_node.next
                cur_node.next = head1.next
                head1.next = cur_node
                head1 = cur_node

        return dummy_node.next


if __name__ == "__main__":
    s = Solution()
