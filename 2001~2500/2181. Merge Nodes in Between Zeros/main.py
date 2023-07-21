"""
Source: https://rb.gy/x45ru
Date: 2023/7/21
Skill:
Ref:
Runtime: 2528 ms, faster than 89.90%
Memory Usage: 106.33 MB, less than 39.63%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        res, head = ListNode(), head.next
        tmp = res
        while head:
            num = 0
            while head.val != 0:
                num += head.val
                head = head.next
            tmp.next = ListNode(val=num)
            tmp = tmp.next
            head = head.next

        return res.next


if __name__ == "__main__":
    s = Solution()
