"""
Source: https://leetcode.com/problems/palindrome-linked-list/
Date: 2023/3/22
Skill:
Runtime: 783 ms, faster than 71.99%
Memory Usage: 39 MB, less than 82.61%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the list is in the range [1, 10^5]
    0 <= Node.val <= 9
    Do it in O(n) time and O(1) space
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
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        num, tail = 1, head
        while tail.next:
            num += 1
            tail = tail.next

        if num == 1:
            return True
        tail = head
        for _ in range((num + 1) // 2):
            tail = tail.next
        prev, next = None, tail.next
        while next:
            tail.next = prev
            prev = tail
            tail = next
            next = next.next
        tail.next = prev
        for _ in range(num // 2):
            if head.val != tail.val:
                return False
            head = head.next
            tail = tail.next
        return True
