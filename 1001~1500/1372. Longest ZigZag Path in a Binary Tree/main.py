"""
Source: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
Date: 2023/4/19
Skill:
Ref:
Runtime: 327 ms, faster than 99.63%
Memory Usage: 60.9 MB, less than 72.89%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [1, 5 * 10^4].
"""

import math
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
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        res = 0

        def dfs(node, cur_length, is_left):
            nonlocal res
            if node.left is None:
                if not is_left:
                    res = max(res, cur_length)
            else:
                if not is_left:
                    dfs(node.left, cur_length + 1, not is_left)
                else:
                    dfs(node.left, 1, True)
            if node.right is None:
                if is_left:
                    res = max(res, cur_length)
            else:
                if is_left:
                    dfs(node.right, cur_length + 1, not is_left)
                else:
                    dfs(node.right, 1, False)

        if root.left:
            dfs(root.left, 1, True)
        if root.right:
            dfs(root.right, 1, False)
        return res


if __name__ == "__main__":
    s = Solution()
