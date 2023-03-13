"""
Source: https://leetcode.com/problems/symmetric-tree/description/
Date: 2023/3/13
Skill:
Runtime: 28 ms, faster than 94.49%
Memory Usage: 14 MB, less than 14.51%
Time complexity:
Space complexity:
Constraints:

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
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        left_queue, right_queue = deque([root]), deque([root])
        while left_queue or right_queue:
            if not (left_queue and right_queue):
                return False
            left_node, right_node = left_queue.popleft(), right_queue.popleft()
            if left_node.left:
                if right_node.right and left_node.left.val == right_node.right.val:
                    left_queue.append(left_node.left)
                    right_queue.append(right_node.right)
                else:
                    return False
            if left_node.right:
                if right_node.left and left_node.right.val == right_node.left.val:
                    left_queue.append(left_node.right)
                    right_queue.append(right_node.left)
                else:
                    return False

        return True


if __name__ == "__main__":
    s = Solution()
