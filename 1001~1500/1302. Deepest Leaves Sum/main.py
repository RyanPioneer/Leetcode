"""
Source: https://rb.gy/b8m6w
Date: 2023/7/21
Skill:
Ref:
Runtime: 222 ms, faster than 47.58%
Memory Usage: 20.11 MB, less than 73.54%
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
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        q = deque([root])
        while q:
            cur_sum, num = 0, len(q)
            for i in range(num):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                cur_sum += node.val
            if len(q) == 0:
                return cur_sum


if __name__ == "__main__":
    s = Solution()

