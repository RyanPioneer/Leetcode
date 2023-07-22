"""
Source: https://rb.gy/4o67w
Date: 2023/7/22
Skill: 觀察每個邊跟他的子節點
Ref:
Runtime: 50 ms, faster than 68.70%
Memory Usage: 16.24 MB, less than 89.82%
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
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        res = 0

        def dfs(node):
            nonlocal res
            if not node:
                return 0
            children_num = 1
            if node.left:
                children_num += dfs(node.left)
                node.val += node.left.val
            if node.right:
                children_num += dfs(node.right)
                node.val += node.right.val

            res += abs(children_num - node.val)
            return children_num

        dfs(root)
        return res


if __name__ == "__main__":
    s = Solution()
