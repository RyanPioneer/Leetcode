"""
Source: https://rb.gy/oxzda
Date: 2023/8/3
Skill:
Ref:
Runtime: 59 ms, faster than 74.15%
Memory Usage: 18.25 MB, less than 14.15%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        def dfs(node):
            if not node.left and not node.right:
                return [chr(ord("a") + node.val)]
            res = []
            if node.left:
                for string in dfs(node.left):
                    res.append(string + chr(ord("a") + node.val))
            if node.right:
                for string in dfs(node.right):
                    res.append(string + chr(ord("a") + node.val))
            return res

        res = dfs(root)
        return min(res)


if __name__ == "__main__":
    s = Solution()
