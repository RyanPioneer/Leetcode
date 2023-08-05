"""
Source: https://rb.gy/myox8
Date: 2023/8/4
Skill: index sort
Ref:
Runtime: 536 ms, faster than 99.03%
Memory Usage: 56.76 MB, less than 76.70%
Time complexity:
Space complexity:
Constraints:
    The number of nodes in the tree is in the range [1, 10^5].
    All the values of the tree are unique.
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        q, res = deque([root]), 0
        while q:
            num = len(q)
            arr = []
            for _ in range(num):
                node = q.popleft()
                arr.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

            arr_sorted, num2idx = sorted(arr), defaultdict(int)
            for i in range(num):
                num2idx[arr_sorted[i]] = i
            for i in range(num):
                while num2idx[arr[i]] != i:
                    idx = num2idx[arr[i]]
                    arr[i], arr[idx] = arr[idx], arr[i]
                    res += 1

        return res


if __name__ == "__main__":
    s = Solution()
