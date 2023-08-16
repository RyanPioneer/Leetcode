"""
Source: https://rb.gy/4gidf
Date: 2023/8/16
Skill:
Ref:
Runtime: 2779 ms, faster than 5.18%
Memory Usage: 36.72 MB, less than 5.18%
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


class SegmentTreeNode:
    def __init__(self, start, end, status=False, left=None, right=None):
        self.start = start
        self.end = end
        self.mid = (start + end) // 2
        self.status = status
        self.left = left
        self.right = right


class SegmentTree:
    def __init__(self, n):
        self.n = n
        self.root = SegmentTreeNode(1, n, False)

    def set_status(self, node: SegmentTreeNode, start, end, status):
        if start <= node.start and end >= node.end:
            node.status = status
            node.left = None
            node.right = None
            return
        if start >= node.end or end <= node.start:
            return
        if not node.left:
            node.left = SegmentTreeNode(node.start, node.mid, node.status)
            node.right = SegmentTreeNode(node.mid, node.end, node.status)
        self.set_status(node.left, start, end, status)
        self.set_status(node.right, start, end, status)
        node.status = node.left.status and node.right.status

    def get_status(self, node: SegmentTreeNode, start, end):
        if start <= node.start and end >= node.end:
            return node.status
        if start >= node.end or end <= node.start:
            return True
        if not node.left:
            return node.status
        return self.get_status(node.left, start, end) and self.get_status(node.right, start, end)


class RangeModule:

    def __init__(self):
        self.tree = SegmentTree(10 ** 9)

    def addRange(self, left: int, right: int) -> None:
        self.tree.set_status(self.tree.root, left, right, True)

    def queryRange(self, left: int, right: int) -> bool:
        return self.tree.get_status(self.tree.root, left, right)

    def removeRange(self, left: int, right: int) -> None:
        self.tree.set_status(self.tree.root, left, right, False)

# Your RangeModule object will be instantiated and called as such:
# obj = RangeModule()
# obj.addRange(left,right)
# param_2 = obj.queryRange(left,right)
# obj.removeRange(left,right)
