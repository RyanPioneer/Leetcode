"""
Source: https://leetcode.com/problems/merge-k-sorted-lists/
Date: 2023/3/5
Skill:
Runtime: 152 ms, faster than 32.78%
Memory Usage: 18.5 MB, less than 17.94%
Time complexity:
Space complexity:
Constraints:
    0 <= lists[i].length <= 500
"""

import math
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
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        sl, num2list, sz, head = SortedList(), defaultdict(list), len(lists), None
        for i in range(sz):
            if lists[i]:
                sl.add(lists[i].val)
                num2list[lists[i].val].append(i)
                lists[i] = lists[i].next

        if len(sl) == 0:
            return head

        head = ListNode(sl[0])
        cur_node = head

        def find_num():
            num = len(num2list[sl[0]])
            for i in range(num):
                list_num = num2list[sl[0]][0]
                if lists[list_num]:
                    sl.add(lists[list_num].val)
                    num2list[lists[list_num].val].append(list_num)
                    lists[list_num] = lists[list_num].next
                num2list[sl[0]].pop(0)
            sl.pop(0)

        find_num()

        while sl:
            cur_node.next = ListNode(sl[0])
            cur_node = cur_node.next
            find_num()

        return head


if __name__ == "__main__":
    s = Solution()
