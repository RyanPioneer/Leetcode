"""
Source: https://rb.gy/4jvit
Date: 2023/7/22
Skill:
Ref:
Runtime: 594 ms, faster than 74.88%
Memory Usage: 57.72 MB, less than 63.10%
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
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        level_sum, q = [], deque([root])
        while q:
            sz, num = len(q), 0
            for _ in range(sz):
                node = q.popleft()
                num += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            level_sum.append(num)

        level_sum.sort(reverse=True)
        return level_sum[k-1] if k <= len(level_sum) else -1


if __name__ == "__main__":
    s = Solution()