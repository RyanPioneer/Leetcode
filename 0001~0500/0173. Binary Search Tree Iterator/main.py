"""
Source: https://rb.gy/ok2i3
Date: 2023/7/4
Skill:
Ref:
Runtime: 95 ms, faster than 17.99%
Memory Usage: 22.3 MB, less than 86.22%
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
class BSTIterator:

    def __init__(self, root: Optional[TreeNode]):
        self.nums, self.pos, stack, cur = [], 0, [root], root
        while cur.left:
            cur = cur.left
            stack.append(cur)
        while stack:
            cur = stack.pop()
            self.nums.append(cur.val)
            if cur.right:
                cur = cur.right
                while cur:
                    stack.append(cur)
                    cur = cur.left

    def next(self) -> int:
        self.pos += 1
        return self.nums[self.pos - 1]

    def hasNext(self) -> bool:
        return self.pos < len(self.nums)


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()

if __name__ == "__main__":
    # s = Solution()
