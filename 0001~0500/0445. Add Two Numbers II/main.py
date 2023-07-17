"""
Source: https://rb.gy/kizp3
Date: 2023/7/17
Skill:
Ref:
Runtime: 89 ms, faster than 23.08%
Memory Usage: 16.32 MB, less than 68.70%
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
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        stack1, stack2, res, carry = [], [], [], 0
        while l1:
            stack1.append(l1.val)
            l1 = l1.next
        while l2:
            stack2.append(l2.val)
            l2 = l2.next
        while stack1 or stack2 or carry:
            if stack1:
                carry += stack1[-1]
                stack1.pop()
            if stack2:
                carry += stack2[-1]
                stack2.pop()
            res.append(carry % 10)
            carry //= 10

        head, idx = ListNode(val=res[-1]), len(res)-1
        tmp = head
        while idx-1 >= 0:
            idx -= 1
            tmp.next = ListNode(val=res[idx])
            tmp = tmp.next
        return head


if __name__ == "__main__":
    s = Solution()
    l1 = ListNode(val=2)
    tmp = l1
    tmp.next = ListNode(val=4)
    tmp = tmp.next
    tmp.next = ListNode(val=3)
    l2 = ListNode(val=5)
    tmp = l2
    tmp.next = ListNode(val=6)
    tmp = tmp.next
    tmp.next = ListNode(val=4)
    res = s.addTwoNumbers(l1, l2)

