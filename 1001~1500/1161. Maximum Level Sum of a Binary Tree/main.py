"""
Source: https://rb.gy/1osqt
Date: 2023/7/22
Skill:
Ref:
Runtime: 292 ms, faster than 89.06%
Memory Usage: 21.11 MB, less than 26.81%
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


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        res, maximum, q, level = 1, root.val, deque([root]), 1
        while q:
            sz, num = len(q), 0
            for _ in range(sz):
                node = q.popleft()
                num += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            if num > maximum:
                maximum = num
                res = level
            level += 1

        return res


if __name__ == "__main__":
    s = Solution()