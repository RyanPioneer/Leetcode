"""
Source: https://rb.gy/wiejn
Date: 2023/7/18
Skill:
Ref:
Runtime: 509 ms, faster than 56.93%
Memory Usage: 29.83 MB, less than 79.11%
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
    def findValueOfPartition(self, nums: List[int]) -> int:
        nums.sort()
        res, sz = nums[-1] - nums[0], len(nums)
        for i in range(sz-1):
            res = min(res, nums[i+1] - nums[i])
        return res


if __name__ == "__main__":
    s = Solution()
