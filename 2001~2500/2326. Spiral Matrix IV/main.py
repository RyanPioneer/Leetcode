"""
Source: https://rb.gy/cntny
Date: 2023/8/5
Skill:
Ref:
Runtime: 993 ms, faster than 95.47%
Memory Usage: 69.01 MB, less than 23.95%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        res = [[-1 for _ in range(n)] for _ in range(m)]
        row, col, x, y = n, m - 1, 0, -1
        while head:
            for _ in range(row):
                if not head:
                    break
                x, y = x, y + 1
                res[x][y] = head.val
                head = head.next
            row -= 1
            for _ in range(col):
                if not head:
                    break
                x, y = x + 1, y
                res[x][y] = head.val
                head = head.next
            col -= 1
            for _ in range(row):
                if not head:
                    break
                x, y = x, y - 1
                res[x][y] = head.val
                head = head.next
            row -= 1
            for _ in range(col):
                if not head:
                    break
                x, y = x - 1, y
                res[x][y] = head.val
                head = head.next
            col -= 1

        return res


if __name__ == "__main__":
    s = Solution()
