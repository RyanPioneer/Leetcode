"""
Source: https://leetcode.com/problems/construct-quad-tree/
Date: 2023/3/3
Skill:
Ref:
Runtime: 121 ms, faster than 42.73%
Memory Usage: 15 MB, less than 16.96%
Time complexity:
Space complexity:
Constraints:
    n == grid.length == grid[i].length
    n == 2^x where 0 <= x <= 6
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight


class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        def construct_range(top, left, length):
            if length == 1:
                return Node(grid[top][left], True)
            topLeft, topRight, bottomLeft, bottomRight = \
                construct_range(top, left, length//2), \
                construct_range(top, left + length//2, length // 2), \
                construct_range(top + length//2, left, length // 2), \
                construct_range(top + length//2, left + length//2, length // 2)

            children = [topLeft, topRight, bottomLeft, bottomRight]
            if all(child.isLeaf and child.val == topLeft.val for child in children):
                return Node(topLeft.val, True)
            else:
                return Node(0, False, topLeft, topRight, bottomLeft, bottomRight)

        return construct_range(0, 0, len(grid))


if __name__ == "__main__":
    s = Solution