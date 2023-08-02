"""
Source: https://rb.gy/flvdv
Date: 2023/8/2
Skill:
Ref:
Runtime: 852 ms, faster than 95.35%
Memory Usage: 30.41 MB, less than 88.37%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def secondGreaterElement(self, nums: List[int]) -> List[int]:
        stack1, stack2, res, sz = [], deque(), [-1 for _ in range(len(nums))], len(nums)
        for i in range(sz):
            while stack2 and nums[stack2[-1]] < nums[i]:
                res[stack2[-1]] = nums[i]
                stack2.pop()
            arr = []
            while stack1 and nums[stack1[-1]] < nums[i]:
                arr.append(stack1.pop())
            while arr:
                stack2.append(arr.pop())
            stack1.append(i)

        return res


if __name__ == "__main__":
    s = Solution()
    nums = [272, 238, 996, 406, 763, 164, 102, 948, 217, 760, 609, 700, 848, 637, 748, 718, 469, 449, 502, 703, 292, 86,
            91, 551, 699, 293, 244, 406, 22, 968, 434, 805, 910, 927, 623, 79, 108, 541, 411]
    res = s.secondGreaterElement(nums)
