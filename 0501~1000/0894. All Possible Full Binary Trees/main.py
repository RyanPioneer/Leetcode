"""
Source: https://rb.gy/17gsq
Date: 2023/7/23
Skill:
Ref:
Runtime: 206 ms, faster than 36.49%
Memory Usage: 26.05 MB, less than 20.07%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 20
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
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        if n % 2 == 0:
            return None
        elif n == 1:
            return [TreeNode()]
        else:
            res = []
            for i in range(1, n-1, 2):
                left = self.allPossibleFBT(i)
                right = self.allPossibleFBT(n-1-i)
                for left_node in left:
                    for right_node in right:
                        root = TreeNode(left=left_node, right=right_node)
                        res.append(root)
            return res


if __name__ == "__main__":
    s = Solution()
