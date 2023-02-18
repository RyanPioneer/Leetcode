"""
Source: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
Date: 2023/2/17
Skill:
Runtime: 35 ms, faster than 56.88%
Memory Usage: 13.9 MB, less than 74.83%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [2, 100].
    0 <= Node.val <= 10^5
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
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        def helper(cur_node, high, low):
            if cur_node == None:
                return high - low
            return min(helper(cur_node.left, cur_node.val, low),
                       helper(cur_node.right, high, cur_node.val))

        return helper(root, math.inf, -math.inf)


if __name__ == "__main__":
    s = Solution