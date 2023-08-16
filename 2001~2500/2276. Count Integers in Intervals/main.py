"""
Source: https://rb.gy/tp3rg
Date: 2023/8/16
Skill:
Ref:
Runtime: 5317 ms, faster than 23.26%
Memory Usage: 295.54 MB, less than 11.63%
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
    def __init__(self, start, end, num=0, left=None, right=None):
        self.start = start
        self.end = end
        self.mid = (start + end) // 2
        self.num = num
        self.left = left
        self.right = right


class SegmentTree:
    def __init__(self, n):
        self.root = SegmentTreeNode(1, n)

    def set_num(self, node: SegmentTreeNode, start, end):
        if start <= node.start and end >= node.end:
            node.num = node.end - node.start + 1
            node.left = None
            node.right = None
            return
        if start > node.end or end < node.start:
            return
        if node.num == node.end - node.start + 1:
            return
        if not node.left:
            node.left = SegmentTreeNode(node.start, node.mid)
            node.right = SegmentTreeNode(node.mid + 1, node.end)
        self.set_num(node.left, start, end)
        self.set_num(node.right, start, end)
        node.num = node.left.num + node.right.num

    def get_status(self, node: SegmentTreeNode, start, end):
        if start <= node.start and end >= node.end:
            return node.num
        if start > node.end or end < node.start:
            return 0
        if not node.left:
            return min(end, node.end) - max(start, node.start) + 1
        return self.get_status(node.left, start, end) + self.get_status(node.right, start, end)


class CountIntervals:

    def __init__(self):
        self.tree = SegmentTree(10 ** 9)

    def add(self, left: int, right: int) -> None:
        self.tree.set_num(self.tree.root, left, right)

    def count(self) -> int:
        return self.tree.get_status(self.tree.root, 0, 10 ** 9)

# Your CountIntervals object will be instantiated and called as such:
# obj = CountIntervals()
# obj.add(left,right)
# param_2 = obj.count()
