"""
Source: https://rb.gy/ukk72
Date: 2023/8/9
Skill:
Ref:
Runtime: 241 ms, faster than 67.74%
Memory Usage: 18.26 MB, less than 6.45%
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
        self.left = left
        self.right = right
        self.update = 0
        self.update_val = 0


class SegmentTree:
    def __init__(self, nums):
        self.nums = nums
        self.n = len(nums)
        self.root = self.build_tree(0, self.n - 1)

    def build_tree(self, start, end):
        if start == end:
            return SegmentTreeNode(start, end, self.nums[start])
        mid = (start + end) // 2
        left_sub_tree = self.build_tree(start, mid)
        right_sub_tree = self.build_tree(mid + 1, end)
        return SegmentTreeNode(start, end, max(left_sub_tree.val, right_sub_tree.val), left_sub_tree, right_sub_tree)

    def query_range_max(self, node, start, end):
        if not node:
            return 0
        if node.update > 0:
            node.val = max(node.val, node.update_val)
            node.update = 0
            if node.left:
                node.left.update += 1
                node.left.update_val = max(node.update_val, node.left.update_val)
            if node.right:
                node.right.update += 1
                node.right.update_val = max(node.update_val, node.right.update_val)
            node.update_val = 0
        if start == node.start and end == node.end:
            return node.val
        if end <= node.mid:
            return self.query_range_max(node.left, start, end)
        elif start > node.mid:
            return self.query_range_max(node.right, start, end)
        else:
            return max(self.query_range_max(node.left, start, node.mid),
                       self.query_range_max(node.right, node.mid + 1, end))

    def update_range_max(self, node, start, end, val):
        if not node:
            return
        if node.update > 0:
            node.val = max(node.val, node.update_val)
            node.update = 0
            if node.left:
                node.left.update += 1
                node.left.update_val = max(node.update_val, node.left.update_val)
            if node.right:
                node.right.update += 1
                node.right.update_val = max(node.update_val, node.right.update_val)
            node.update_val = 0
        if start == node.start and end == node.end:
            node.val = max(node.val, val)
            if node.left:
                node.left.update += 1
                node.left.update_val = max(val, node.left.update_val)
            if node.right:
                node.right.update += 1
                node.right.update_val = max(val, node.right.update_val)
        elif end <= node.mid:
            self.update_range_max(node.left, start, end, val)
            node.val = max(node.val, node.left.val)
        elif start > node.mid:
            self.update_range_max(node.right, start, end, val)
            node.val = max(node.val, node.right.val)
        else:
            if node.left:
                self.update_range_max(node.left, start, node.mid, val)
                node.val = max(node.val, node.left.val)
            if node.right:
                self.update_range_max(node.right, node.mid + 1, end, val)
                node.val = max(node.val, node.right.val)


class Solution:
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        pos2idx, pos_set, res = defaultdict(int), set(), []
        for position in positions:
            pos_set.add(position[0])
            pos_set.add(position[0] + position[1])
        pos = list(pos_set)
        pos.sort()
        for i in range(len(pos)):
            pos2idx[pos[i]] = i

        tree, max_height, sz = SegmentTree([0 for _ in range(len(pos))]), 0, len(pos)
        for position in positions:
            idx1, idx2 = pos2idx[position[0]], pos2idx[position[0] + position[1]]
            height = tree.query_range_max(tree.root, idx1 + 1, idx2)
            new_height = height + position[1]
            max_height = max(max_height, new_height)
            res.append(max_height)
            tree.update_range_max(tree.root, idx1 + 1, idx2, new_height)
        return res


if __name__ == "__main__":
    s = Solution()
    positions = [[1, 5], [2, 2], [7, 5]]
    res = s.fallingSquares(positions)
    print(res)
