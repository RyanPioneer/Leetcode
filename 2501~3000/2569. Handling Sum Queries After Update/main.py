"""
Source: https://rb.gy/aninu
Date: 2023/8/8
Skill:
Ref:
Runtime: 3065 ms, faster than 55.56%
Memory Usage: 85.52 MB, less than 6.35%
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
    def __init__(self, start, end, val, left=None, right=None):
        self.start = start
        self.end = end
        self.mid = (start + end) // 2
        self.val = val
        self.flip_time = 0
        self.left = left
        self.right = right


class SegmentTree:
    def __init__(self, nums):
        self.n = len(nums)
        self.nums = nums
        self.root = self.build_tree(0, self.n - 1)

    def build_tree(self, start, end):
        if start == end:
            return SegmentTreeNode(start, end, self.nums[start])
        mid = (start + end) // 2
        left_sub_tree = self.build_tree(start, mid)
        right_sub_tree = self.build_tree(mid + 1, end)
        return SegmentTreeNode(start, end, left_sub_tree.val + right_sub_tree.val,
                               left_sub_tree, right_sub_tree)

    def update_delta(self, node, left, right):
        if node.flip_time % 2 == 1:
            node.val = (node.end - node.start + 1) - node.val
            if node.left:
                node.left.flip_time += 1
            if node.right:
                node.right.flip_time += 1
        node.flip_time = 0
        if node.start > right or node.end < left:
            return
        if node.start >= left and node.end <= right:
            node.val = (node.end - node.start + 1) - node.val
            if node.left:
                node.left.flip_time += 1
            if node.right:
                node.right.flip_time += 1
            return
        val = 0
        if node.left:
            self.update_delta(node.left, left, right)
            val += node.left.val
        if node.right:
            self.update_delta(node.right, left, right)
            val += node.right.val
        node.val = val

    def query_range_sum(self, node, start, end):
        if node.flip_time % 2 == 1:
            node.val = (node.end - node.start + 1) - node.val
            node.left.flip_time += 1
            node.right.flip_time += 1
        node.flip_time = 0
        if node.start == start and node.end == end:
            return node.val
        elif end <= node.mid:
            return self.query_range_sum(node.left, start, end)
        elif start > node.mid:
            return self.query_range_sum(node.right, start, end)
        else:
            return self.query_range_sum(node.left, start, node.mid) + self.query_range_sum(node.right, node.mid + 1,
                                                                                           end)


class Solution:
    def handleQuery(self, nums1: List[int], nums2: List[int], queries: List[List[int]]) -> List[int]:
        tree, res, total, sz = SegmentTree(nums1), [], sum(nums2), len(nums1)
        for query in queries:
            if query[0] == 1:
                tree.update_delta(tree.root, query[1], query[2])
            elif query[0] == 2:
                total += query[1] * tree.query_range_sum(tree.root, 0, sz - 1)
            else:
                res.append(total)
        return res


if __name__ == "__main__":
    s = Solution()
