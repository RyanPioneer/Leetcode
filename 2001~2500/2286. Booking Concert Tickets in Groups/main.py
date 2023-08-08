"""
Source: https://rb.gy/t5rur
Date: 2023/8/8
Skill:
Ref:
Runtime: 4958 ms, faster than 8.70%
Memory Usage: 83.6 MB, less than 6.52%
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
            return self.query_range_sum(node.left, start, node.mid) + self.query_range_sum(node.right, node.mid + 1, end)

    def query_range_max(self, node, start, end):
        if node.start == start and node.end == end:
            return node.max_val
        elif end <= node.mid:
            return self.query_range_max(node.left, start, end)
        elif start > node.mid:
            return self.query_range_max(node.right, start, end)
        else:
            return max(self.query_range_max(node.left, start, node.mid), self.query_range_max(node.right, node.mid + 1, end))


class BookMyShow:

    def __init__(self, n: int, m: int):
        self.n, self.m, self.s = n, m, 0
        self.seats = [m for _ in range(n)]
        self.tree = SegmentTree(self.seats)

    def gather(self, k: int, maxRow: int) -> List[int]:
        l, r = 0, maxRow
        while l < r:
            mid = (l + r) // 2
            if self.tree.query_range_max(self.tree.root, l, mid) >= k:
                r = mid
            else:
                l = mid + 1
        if self.tree.query_range_max(self.tree.root, l, l) < k:
            return []
        self.seats[l] -= k
        self.tree.update_delta(self.tree.root, l, -k)
        return [l, self.m - self.seats[l] - k]

    def scatter(self, k: int, maxRow: int) -> bool:
        if self.tree.query_range_sum(self.tree.root, 0, maxRow) < k:
            return False
        while k > 0:
            t = min(k, self.seats[self.s])
            self.tree.update_delta(self.tree.root, self.s, -t)
            self.seats[self.s] -= t
            k -= t
            if self.seats[self.s] == 0:
                self.s += 1
        return True


# Your BookMyShow object will be instantiated and called as such:
# obj = BookMyShow(n, m)
# param_1 = obj.gather(k,maxRow)
# param_2 = obj.scatter(k,maxRow)



if __name__ == "__main__":
    s = BookMyShow()
