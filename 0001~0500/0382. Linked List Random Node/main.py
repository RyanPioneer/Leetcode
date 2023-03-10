"""
Source: https://leetcode.com/problems/linked-list-random-node/
Date: 2023/3/10
Skill: Reservoir sampling
Runtime: 181 ms, faster than 16.73%
Memory Usage: 17.2 MB, less than 97.21%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the linked list will be in the range [1, 10^4].
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
    import random

    def __init__(self, head: Optional[ListNode]):
        self.node = head

    def getRandom(self) -> int:
        res, cnt, cur_node = 0, 0, self.node
        while cur_node:
            cnt += 1
            if not random.randint(0, 10**4) % cnt:
                res = cur_node.val
            cur_node = cur_node.next

        return res

# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()


if __name__ == "__main__":
    s = Solution()
