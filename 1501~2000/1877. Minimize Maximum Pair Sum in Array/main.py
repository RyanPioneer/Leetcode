"""
Source: https://rb.gy/3sa1i
Date: 2023/8/7
Skill:
Ref:
Runtime: 992 ms, faster than 90.06%
Memory Usage: 30.87 MB, less than 29.97%
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
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        res, sz = 0, len(nums)
        for i in range(sz // 2):
            res = max(res, nums[i] + nums[sz - 1 - i])
        return res


if __name__ == "__main__":
    s = Solution()
