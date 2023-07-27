"""
Source: https://rb.gy/rwsx2
Date: 2023/7/27
Skill:
Ref:
Runtime: 595 ms, faster than 80.85%
Memory Usage: 26.15 MB, less than 63.14%
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
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        q = deque([cloned])
        while q:
            node = q.popleft()
            if node.val == target.val:
                return node
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)


if __name__ == "__main__":
    s = Solution()
