"""
Source: https://leetcode.com/problems/check-completeness-of-a-binary-tree/
Date: 2023/3/15
Skill:
Runtime: 31 ms, faster than 91.2%
Memory Usage: 13.9 MB, less than 18.83%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [1, 100].
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
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        q, flag = deque([root]), False
        while q:
            cur_node = q.popleft()
            if cur_node.left:
                if flag:
                    return False
                q.append(cur_node.left)
            else:
                flag = True
            if cur_node.right:
                if flag:
                    return False
                q.append(cur_node.right)
            else:
                flag = True

        return True


if __name__ == "__main__":
    s = Solution()
