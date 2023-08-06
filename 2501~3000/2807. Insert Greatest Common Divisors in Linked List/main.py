"""
Source: https://rb.gy/d5xx0
Date: 2023/8/6
Skill:
Ref:
Runtime: 102 ms, faster than 100.00%
Memory Usage: 20.92 MB, less than 100.00%
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
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def get_gcd(x, y):
            if x % y == 0:
                return y
            else:
                return get_gcd(y, x % y)

        tmp = head
        while tmp.next:
            node = ListNode(val=get_gcd(tmp.val, tmp.next.val), next=tmp.next)
            tmp.next = node
            tmp = tmp.next.next

        return head


if __name__ == "__main__":
    s = Solution()
