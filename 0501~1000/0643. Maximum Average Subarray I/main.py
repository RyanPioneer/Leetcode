"""
Source: https://rb.gy/cc0p5
Date: 2023/7/26
Skill:
Ref:
Runtime: 1156 ms, faster than 88.23%
Memory Usage: 28.08 MB, less than 67.32%
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
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        sz, cur_sum, res = len(nums), sum(nums[:k]), sum(nums[:k])
        for i in range(k, sz):
            cur_sum += nums[i]
            cur_sum -= nums[i - k]
            res = max(res, cur_sum)
        return res / k


if __name__ == "__main__":
    s = Solution()
