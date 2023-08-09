"""
Source: https://rb.gy/kcrek
Date: 2023/8/9
Skill:
Ref:
Runtime: 309 ms, faster than 92.14%
Memory Usage: 27.83 MB, less than 23.80%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 10 ** 5
    -10 ** 9 <= nums[i] <= 10 ** 9
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def minDifference(self, nums: List[int]) -> int:
        if len(nums) <= 4:
            return 0
        nums.sort()
        return min(nums[-1] - nums[3], nums[-2] - nums[2], nums[-3] - nums[1], nums[-4] - nums[0])


if __name__ == "__main__":
    s = Solution()
