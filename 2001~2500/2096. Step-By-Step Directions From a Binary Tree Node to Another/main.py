"""
Source: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
Date: 2023/4/12
Skill:
Ref:
Runtime: 973 ms, faster than 27.29%
Memory Usage: 136.4 MB, less than 57.94%
Time complexity:
Space complexity:
Constraints:
    2 <= n <= 10^5
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
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        string, start_dir, dest_dir, find_num = "", "", "", 0

        def dfs(cur_node):
            nonlocal string, start_dir, dest_dir, find_num
            if cur_node.val == startValue:
                start_dir = string
                find_num += 1
                if find_num == 2:
                    return
            if cur_node.val == destValue:
                dest_dir = string
                find_num += 1
                if find_num == 2:
                    return
            if cur_node.left and find_num < 2:
                string += "L"
                dfs(cur_node.left)
                string = string[:-1]
            if cur_node.right and find_num < 2:
                string += "R"
                dfs(cur_node.right)
                string = string[:-1]

        dfs(root)
        LCA = 0
        while LCA < len(start_dir) and LCA < len(dest_dir) and start_dir[LCA] == dest_dir[LCA]:
            LCA += 1
        dest_dir = dest_dir[LCA:]
        for _ in range(len(start_dir) - LCA):
            dest_dir = "U" + dest_dir

        return dest_dir


if __name__ == "__main__":
    s = Solution()
