"""
Source: https://rb.gy/1bf9l
Date: 2023/8/8
Skill:
Ref:
Runtime: 5411 ms, faster than 5.51%
Memory Usage: 89.95 MB, less than 5.51%
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
    def __init__(self, start, end, val, max_val=None, left=None, right=None):
        self.start = start
        self.end = end
        self.mid = (start + end) // 2
        self.val = val
        self.max_val = max_val
        self.left = left
        self.right = right


class SegmentTree:
    def __init__(self, nums):
        self.n = len(nums)
        self.nums = nums
        self.root = self.build_tree(0, self.n - 1)

    def build_tree(self, start, end):
        if start == end:
            return SegmentTreeNode(start, end, self.nums[start], self.nums[start])
        mid = (start + end) // 2
        left_sub_tree = self.build_tree(start, mid)
        right_sub_tree = self.build_tree(mid + 1, end)
        return SegmentTreeNode(start, end, left_sub_tree.val + right_sub_tree.val,
                               max(left_sub_tree.max_val, right_sub_tree.max_val),
                               left_sub_tree, right_sub_tree)

    def update_delta(self, node, idx, delta):
        if node.start == idx and node.end == idx:
            node.val += delta
            node.max_val += delta
        elif idx <= node.mid:
            node.val -= node.left.val
            self.update_delta(node.left, idx, delta)
            node.val += node.left.val
            node.max_val = max(node.left.max_val, node.right.max_val)
        else:
            node.val -= node.right.val
            self.update_delta(node.right, idx, delta)
            node.val += node.right.val
            node.max_val = max(node.left.max_val, node.right.max_val)

    def query_range_sum(self, node, start, end):
        if node.start == start and node.end == end:
            return node.val
        elif end <= node.mid:
            return self.query_range_sum(node.left, start, end)
        elif start > node.mid:
            return self.query_range_sum(node.right, start, end)
        else:
            return self.query_range_sum(node.left, start, node.mid) + self.query_range_sum(node.right, node.mid + 1,
                                                                                           end)

    def query_range_max(self, node, start, end):
        if node.start == start and node.end == end:
            return node.max_val
        elif end <= node.mid:
            return self.query_range_max(node.left, start, end)
        elif start > node.mid:
            return self.query_range_max(node.right, start, end)
        else:
            return max(self.query_range_max(node.left, start, node.mid),
                       self.query_range_max(node.right, node.mid + 1, end))


class Solution:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        num2idx, sz, res = defaultdict(int), len(nums1), 0
        for i in range(sz):
            num2idx[nums1[i]] = i
        tree = SegmentTree([0 for _ in range(sz)])
        for i in range(sz):
            smaller = tree.query_range_sum(tree.root, 0, num2idx[nums2[i]])
            bigger = sz - 1 - num2idx[nums2[i]] - (i - smaller)
            res += smaller * bigger
            tree.update_delta(tree.root, num2idx[nums2[i]], 1)
        return res


if __name__ == "__main__":
    s = Solution()
    nums1, nums2 = [2, 0, 1, 3], [0, 1, 2, 3]
    res = s.goodTriplets(nums1, nums2)
    print(res)
