"""
Source: https://leetcode.com/problems/maximum-width-of-binary-tree/
Date: 2023/3/15
Skill:
Runtime: 47 ms, faster than 64.61%
Memory Usage: 414.8 MB, less than 67.90%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [1, 3000].
"""

import math
import random
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        q, res = deque([(root, 1)]), 1
        while q:
            sz = len(q)
            nodes_index = []
            for _ in range(sz):
                cur_node, cur_index = q.popleft()
                nodes_index.append(cur_index)
                if cur_node.left:
                    q.append((cur_node.left, cur_index * 2))
                if cur_node.right:
                    q.append((cur_node.right, cur_index * 2 + 1))

            res = max(res, max(nodes_index) - min(nodes_index) + 1)

        return res


if __name__ == "__main__":
    s = Solution()
