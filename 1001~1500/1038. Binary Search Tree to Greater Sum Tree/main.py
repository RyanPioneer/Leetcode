"""
Source: https://rb.gy/k2kij
Date: 2023/7/21
Skill:
Ref:
Runtime: 47 ms, faster than 61.83%
Memory Usage: 16.5 MB, less than 25.13%
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
    def bstToGst(self, root: TreeNode) -> TreeNode:
        cur_node, cur_num = root, 0
        stack, nums = [cur_node], 0
        while cur_node.right:
            cur_node = cur_node.right
            stack.append(cur_node)
        while stack:
            cur_node = stack.pop()
            cur_num += cur_node.val
            cur_node.val = cur_num
            if cur_node.left:
                cur_node = cur_node.left
                stack.append(cur_node,)
                while cur_node.right:
                    cur_node = cur_node.right
                    stack.append(cur_node)

        return root


if __name__ == "__main__":
    s = Solution()
