"""
Source: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
Date: 2023/4/21
Skill:
Ref:
Runtime: 400 ms, faster than 62.55%
Memory Usage: 20.7 MB, less than 26.68%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        lo, hi = 1, max(nums)

        def check(divisor):
            res = 0
            for num in nums:
                res += (num + divisor - 1) // divisor
            return res <= threshold

        while lo < hi:
            mid = (lo + hi) // 2
            if check(mid):
                hi = mid
            else:
                lo = mid + 1

        return lo


if __name__ == "__main__":
    s = Solution()
