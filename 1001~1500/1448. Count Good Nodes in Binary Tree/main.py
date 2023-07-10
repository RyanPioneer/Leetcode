"""
Source: https://rb.gy/9u6ah
Date: 2023/7/8
Skill:
Ref:
Runtime: 252 ms, faster than 72.77%
Memory Usage: 35 MB, less than 93.68%
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
    def goodNodes(self, root: TreeNode) -> int:
        res = 0

        def dfs(node, cur_max):
            nonlocal res
            if not node:
                return
            if node.val >= cur_max:
                res += 1
            cur_max = max(cur_max, node.val)
            dfs(node.left, cur_max)
            dfs(node.right, cur_max)

        dfs(root, -sys.maxsize)
        return res


if __name__ == "__main__":
    s = Solution()
