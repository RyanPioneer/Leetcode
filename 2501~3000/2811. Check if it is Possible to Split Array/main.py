"""
Source: https://rb.gy/xtavj
Date: 2023/8/6
Skill:
Ref:
Runtime: 52 ms, faster than 100.00%
Memory Usage: 16.2 MB, less than 93.83%
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
    def canSplitArray(self, nums: List[int], m: int) -> bool:
        if len(nums) <= 2:
            return True
        for i in range(len(nums) - 1):
            if nums[i] + nums[i + 1] >= m:
                return True
        return False


if __name__ == "__main__":
    s = Solution()
