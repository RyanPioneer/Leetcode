"""
Source: https://rb.gy/pe1wk
Date: 2023/7/18
Skill:
Ref:
Runtime: 89 ms, faster than 72.85%
Memory Usage: 17.24 MB, less than 38.79%
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
    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        idx, sz, stack = 0, len(traversal), []
        while idx < sz and traversal[idx] != "-":
            idx += 1
        root = TreeNode(val=int(traversal[:idx]))
        stack.append([0, root])
        while idx < sz:
            depth = 0
            while traversal[idx] == "-":
                idx += 1
                depth += 1
            i = idx
            while idx < sz and traversal[idx] != "-":
                idx += 1
            new_node = TreeNode(val=int(traversal[i:idx]))
            while stack[-1][0] >= depth:
                stack.pop()
            if not stack[-1][1].left:
                stack[-1][1].left = new_node
            else:
                stack[-1][1].right = new_node
            stack.append([depth, new_node])

        return root


if __name__ == "__main__":
    s = Solution()
