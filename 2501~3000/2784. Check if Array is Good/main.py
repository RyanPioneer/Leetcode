"""
Source: https://rb.gy/8mm39
Date: 2023/7/23
Skill:
Ref:
Runtime: 62 ms, faster than 50.00%
Memory Usage: 16.3 MB, less than 100.00%
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
    def isGood(self, nums: List[int]) -> bool:
        sz, time = len(nums), [0 for _ in range(len(nums))]
        for num in nums:
            if num >= sz:
                return False
            elif time[num] == 1 and num != sz - 1:
                return False
            else:
                time[num] += 1

        return True


if __name__ == "__main__":
    s = Solution()
