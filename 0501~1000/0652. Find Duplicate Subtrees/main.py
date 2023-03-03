"""
Source: https://leetcode.com/problems/find-duplicate-subtrees/
Date: 2023/3/3
Skill:
Ref:
Runtime: 51 ms, faster than 72.97%
Memory Usage: 16.6 MB, less than 78.59%
Time complexity:
Space complexity:
Constraints:
    The number of the nodes in the tree will be in the range [1, 5000]
    -200 <= Node.val <= 200
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
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        key2ID, ket2count, res = {}, {}, []

        def getID(node):
            if not node:
                return 0
            key = str(node.val) + "#" + str(getID(node.left)) + "#" + str(getID(node.right))
            if key not in key2ID:
                key2ID[key] = len(key2ID) + 1
                ket2count[key] = 1
            else:
                ket2count[key] += 1
                if ket2count[key] == 2:
                    res.append(node)

            return key2ID[key]

        getID(root)
        return res


if __name__ == "__main__":
    s = Solution