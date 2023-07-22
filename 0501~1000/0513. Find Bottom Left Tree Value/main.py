"""
Source: https://rb.gy/soycv
Date: 2023/7/22
Skill:
Ref:
Runtime: 49 ms, faster than 95.86%
Memory Usage: 18.78 MB, less than 78.24%
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
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        res, q = None, deque([root])
        while q:
            sz = len(q)
            res = q[0].val
            for _ in range(sz):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

        return res


if __name__ == "__main__":
    s = Solution()
