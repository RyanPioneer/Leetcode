"""
Source: https://rb.gy/2tcnk
Date: 2023/8/9
Skill:
Ref:
Runtime: 881 ms, faster than 94.19%
Memory Usage: 31.02 MB, less than 43.87%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 10 ** 5
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        nums.sort()
        lo, hi, sz = 0, nums[-1] - nums[0], len(nums)
        while lo < hi:
            mid = (lo + hi) // 2
            num, idx = 0, 0
            while idx + 1 < sz:
                if nums[idx + 1] - nums[idx] <= mid:
                    idx += 2
                    num += 1
                else:
                    idx += 1
            if num >= p:
                hi = mid
            else:
                lo = mid + 1

        return lo


if __name__ == "__main__":
    s = Solution()
