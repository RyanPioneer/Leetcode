"""
Source: https://rb.gy/15u0w
Date: 2023/7/18
Skill:
Ref:
Runtime: 1171 ms, faster than 90.46%
Memory Usage: 30.49 MB, less than 82.38%
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
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        nums.sort()
        left, right, sz, res = 0, 0, len(nums), 0
        while right < sz:
            while right < sz and nums[right] <= nums[left] + 2 * k:
                right += 1
            res = max(res, right - left)
            left += 1

        return res


if __name__ == "__main__":
    s = Solution()
