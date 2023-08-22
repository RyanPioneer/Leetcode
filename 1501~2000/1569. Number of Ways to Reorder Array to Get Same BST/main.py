"""
Source: https://rb.gy/wuo2o
Date: 2023/8/22
Skill:
Ref:
Runtime: 210 ms, faster than 25.71%
Memory Usage: 17.6 MB, less than 98.59%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 1000
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right
from functools import cache


class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        self.left_num = 0
        self.right_num = 0


class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        mod, n, root = 10 ** 9 + 7, len(nums), TreeNode(nums[0])
        for i in range(1, n):
            node = root
            while True:
                if nums[i] < node.val:
                    node.left_num += 1
                    if node.left:
                        node = node.left
                    else:
                        node.left = TreeNode(nums[i])
                        break
                else:
                    node.right_num += 1
                    if node.right:
                        node = node.right
                    else:
                        node.right = TreeNode(nums[i])
                        break

        def dfs(node):
            num = math.comb(node.left_num + node.right_num, node.left_num) % mod
            if node.left:
                num *= dfs(node.left) % mod
            if node.right:
                num *= dfs(node.right) % mod
            return num % mod

        return dfs(root) - 1


if __name__ == "__main__":
    s = Solution()
    nums = [2, 1, 3]
    res = s.numOfWays(nums)
    print(res)
