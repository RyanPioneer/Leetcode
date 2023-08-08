"""
Source: https://rb.gy/ot9mw
Date: 2023/8/8
Skill:
Ref:
Runtime: 6034 ms, faster than 20.93%
Memory Usage: 76.14 MB, less than 8.37%
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
    def __init__(self, start, end, max_val, left=None, right=None):
        self.start = start
        self.end = end
        self.mid = (start + end) // 2
        self.max_val = max_val
        self.left = left
        self.right = right


class SegmentTree:
    def __init__(self, nums):
        self.nums = nums
        self.root = self.build_tree(0, len(nums) - 1)

    def build_tree(self, left, right):
        if left == right:
            return SegmentTreeNode(left, right, self.nums[left])
        mid = (left + right) // 2
        left_tree = self.build_tree(left, mid)
        right_tree = self.build_tree(mid + 1, right)
        return SegmentTreeNode(left, right, max(left_tree.max_val, right_tree.max_val), left_tree, right_tree)

    def update_tree(self, node, idx, val):
        if node.start == idx and node.end == idx:
            node.max_val = val
            return
        if idx <= node.mid:
            self.update_tree(node.left, idx, val)
        else:
            self.update_tree(node.right, idx, val)
        node.max_val = max(node.left.max_val, node.right.max_val)

    def query_range(self, node, left, right):
        if node.start == left and node.end == right:
            return node.max_val
        if right <= node.mid:
            return self.query_range(node.left, left, right)
        elif left > node.mid:
            return self.query_range(node.right, left, right)
        else:
            return max(self.query_range(node.left, left, node.mid), self.query_range(node.right, node.mid + 1, right))


class Solution:
    def lengthOfLIS(self, nums: List[int], k: int) -> int:
        arr, res = [0 for _ in range(max(nums) + 1)], 0
        segment_tree = SegmentTree(arr)
        for num in nums:
            length = segment_tree.query_range(segment_tree.root, max(0, num - k), max(0, num - 1))
            segment_tree.update_tree(segment_tree.root, num, length + 1)
            res = max(res, length + 1)
        return res


if __name__ == "__main__":
    s = Solution()
