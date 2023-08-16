"""
Source: https://rb.gy/f1aau
Date: 2023/8/16
Skill:
Ref:
Runtime: TLE
Memory Usage:
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
        self.cnt = 0
        self.left = left
        self.right = right


class SegmentTree:
    def __init__(self, nums):
        self.nums = nums
        self.n = len(nums) - 1
        self.root = self.build_tree(0, self.n)

    def build_tree(self, left, right):
        if left == right:
            return SegmentTreeNode(left, right, self.nums[left])
        mid = (left + right) // 2
        left_sub_tree = self.build_tree(left, mid)
        right_sub_tree = self.build_tree(mid + 1, right)
        return SegmentTreeNode(left, right, max(left_sub_tree.val, right_sub_tree.val), left_sub_tree, right_sub_tree)

    def query_max_range(self, node: SegmentTreeNode, left, right):
        if node.end < left or node.start > right:
            return -sys.maxsize
        elif node.start >= left and node.end <= right:
            return node.val
        elif right <= node.mid:
            return self.query_max_range(node.left, left, right)
        elif left >= node.mid + 1:
            return self.query_max_range(node.right, left, right)
        else:
            left_max = self.query_max_range(node.left, left, node.mid)
            right_max = self.query_max_range(node.right, node.mid + 1, right)
            return max(left_max, right_max)

    def update_num(self, node: SegmentTreeNode, idx, val, cnt):
        if node.start == idx and node.end == idx:
            node.cnt += cnt
            if node.cnt == 0:
                node.val = 0
            else:
                node.val = val
            return
        elif idx <= node.mid:
            self.update_num(node.left, idx, val, cnt)
        else:
            self.update_num(node.right, idx, val, cnt)
        val = 0
        if node.left:
            val = max(node.left.val, val)
        if node.right:
            val = max(node.right.val, val)
        node.val = val


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res, sz, offset = [], len(nums), 10 ** 4
        tree = SegmentTree([0 for _ in range(2 * offset + 1)])
        for i in range(k):
            tree.update_num(tree.root, nums[i] + offset, nums[i] + offset, 1)
        res.append(tree.query_max_range(tree.root, 0, 2 * offset) - offset)
        for i in range(k, sz):
            tree.update_num(tree.root, nums[i - k] + offset, nums[i - k] + offset, -1)
            tree.update_num(tree.root, nums[i] + offset, nums[i] + offset, 1)
            res.append(tree.query_max_range(tree.root, 0, 2 * offset) - offset)
        return res


if __name__ == "__main__":
    s = Solution()
