"""
Source: https://rb.gy/iwtyd
Date: 2023/7/27
Skill:
Ref:
Runtime: 37 ms, faster than 97.67%
Memory Usage: 16.3 MB, less than 73.14%
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


class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        res, sz = [], len(nums)
        for i in range(sz):
            res.insert(index[i], nums[i])
        return res


if __name__ == "__main__":
    s = Solution()
