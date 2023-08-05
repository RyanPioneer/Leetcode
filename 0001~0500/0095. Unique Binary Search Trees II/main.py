"""
Source: https://rb.gy/ypwoj
Date: 2023/8/5
Skill:
Ref:
Runtime: 65 ms, faster than 74.74%
Memory Usage: 18.53 MB, less than 7.09%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 8
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
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        def gen_tree(nums):
            if len(nums) == 0:
                return [None]
            sz, res = len(nums), []
            for i in range(sz):
                for left_tree in gen_tree(nums[:i]):
                    for right_tree in gen_tree(nums[i + 1:]):
                        new_root = TreeNode(val=nums[i], left=left_tree, right=right_tree)
                        res.append(new_root)
            return res

        return gen_tree([i + 1 for i in range(n)])


if __name__ == "__main__":
    s = Solution()
