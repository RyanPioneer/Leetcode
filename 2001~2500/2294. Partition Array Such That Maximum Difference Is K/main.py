"""
Source: https://rb.gy/mcz3v
Date: 2023/7/18
Skill:
Ref:
Runtime: 923 ms, faster than 40.75%
Memory Usage: 31.03 MB, less than 40.44%
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
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        left, sz, res = 0, len(nums), 1
        while True:
            right = left + 1
            while right < sz and nums[right] <= nums[left] + k:
                right += 1
            if right == sz:
                return res
            left = right
            res += 1


if __name__ == "__main__":
    s = Solution()
