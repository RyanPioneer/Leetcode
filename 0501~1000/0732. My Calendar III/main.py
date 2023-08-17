"""
Source: https://rb.gy/zyltq
Date: 2023/8/17
Skill:
Ref:
Runtime: 850 ms, faster than 68.63%
Memory Usage: 24.7 MB, less than 5.39%
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
        self.node_count = num
        self.total_count = 0
        self.left = left
        self.right = right


class SegmentTree:
    def __init__(self, n):
        self.root = SegmentTreeNode(0, n)

    def set_num(self, node: SegmentTreeNode, start, end):
        if start <= node.start and end >= node.end:
            node.node_count += 1
            node.total_count += 1
            return
        if start > node.end or end < node.start:
            return
        if not node.left:
            node.left = SegmentTreeNode(node.start, node.mid)
            node.right = SegmentTreeNode(node.mid + 1, node.end)
        self.set_num(node.left, start, end)
        self.set_num(node.right, start, end)
        node.total_count = max(node.left.total_count, node.right.total_count) + node.node_count


class MyCalendarThree:

    def __init__(self):
        self.tree = SegmentTree(10 ** 9)

    def book(self, startTime: int, endTime: int) -> int:
        self.tree.set_num(self.tree.root, startTime, endTime - 1)
        return self.tree.root.total_count

# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(startTime,endTime)
