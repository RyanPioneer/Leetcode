"""
Source: https://leetcode.com/problems/count-increasing-quadruplets/
Date: 2023/8/9
Skill:
Runtime: TLE
Memory Usage:
Time complexity:
Space complexity:
Constraints:
    4 <= nums.length <= 4000
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class SegmentTreeNode:
    def __init__(self, start, end, val, left=None, right=None):
        self.start = start
        self.end = end
        self.mid = (start + end) // 2
        self.val = val
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
        return SegmentTreeNode(start, end, left_sub_tree.val + right_sub_tree.val, left_sub_tree, right_sub_tree)

    def query_range_sum(self, node, start, end):
        if not node:
            return 0
        elif node.start >= start and node.end <= end:
            return node.val
        elif node.start > end or node.end < start:
            return 0
        elif end <= node.mid:
            return self.query_range_sum(node.left, start, end)
        elif node.mid + 1 <= start:
            return self.query_range_sum(node.right, start, end)
        else:
            return self.query_range_sum(node.left, start, node.mid) + self.query_range_sum(node.right, node.mid + 1,
                                                                                           end)

    def update_delta(self, node, idx, delta):
        if node.start == idx and node.end == idx:
            node.val += delta
        elif idx <= node.mid:
            self.update_delta(node.left, idx, delta)
            node.val += delta
        else:
            self.update_delta(node.right, idx, delta)
            node.val += delta


class Solution:
    def countQuadruplets(self, nums: List[int]) -> int:
        sz, res = len(nums), 0
        smaller_before = SegmentTree([0 for _ in range(sz + 1)])
        smaller_before.update_delta(smaller_before.root, nums[0], 1)
        for i in range(1, sz - 2):
            bigger_after = SegmentTree([0 for _ in range(sz + 1)])
            bigger_after.update_delta(bigger_after.root, nums[-1], 1)
            for j in range(sz - 2, i, -1):
                if nums[i] > nums[j]:
                    smaller = smaller_before.query_range_sum(smaller_before.root, 0, nums[j])
                    bigger = bigger_after.query_range_sum(bigger_after.root, nums[i], sz)
                    print(i, j, smaller, bigger)
                    res += smaller * bigger
                bigger_after.update_delta(bigger_after.root, nums[j], 1)
            smaller_before.update_delta(smaller_before.root, nums[i], 1)

        return res


if __name__ == "__main__":
    s = Solution()
    nums = [1, 3, 5, 2, 4]
    res = s.countQuadruplets(nums)
    print(res)

