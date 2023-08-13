"""
Source: https://rb.gy/8g5mn
Date: 2023/8/13
Skill:
Ref:
Runtime: 433 ms, faster than 100%
Memory Usage: 32.6 MB, less than 100%
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
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def helper(node, parent):
            nonlocal head
            if not node.next:
                if node.val * 2 >= 10 and not parent:
                    new_node = ListNode(node.val * 2 // 10, node)
                    node.val = node.val * 2 % 10
                    head = new_node
                else:
                    node.val = node.val * 2
            else:
                helper(node.next, node)
                node.val = node.val * 2 + node.next.val // 10
                node.next.val %= 10
                if node.val >= 10 and not parent:
                    new_node = ListNode(node.val // 10, node)
                    node.val = node.val % 10
                    head = new_node

        helper(head, None)
        return head


if __name__ == "__main__":
    s = Solution()
