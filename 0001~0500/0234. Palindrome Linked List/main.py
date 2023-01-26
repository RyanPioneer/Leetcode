"""
Source: https://leetcode.com/problems/palindrome-linked-list/
Date: 2023/1/25
Skill:
Runtime: 29 ms, faster than 90.42%
Memory Usage: 13.8 MB, less than 66.28%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the list is in the range [1, 10^5].
    0 <= Node.val <= 9
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
