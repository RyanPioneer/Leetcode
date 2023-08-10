"""
Source: https://rb.gy/rdvhg
Date: 2023/8/9
Skill:
Ref:
Runtime: 746 ms, faster than 98.17%
Memory Usage: 31.72 MB, less than 23.29%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length, k <= 10 ** 5
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        res, heap = 0, [-num for num in nums]
        heapify(heap)
        for _ in range(k):
            num = heappop(heap)
            res -= num
            heappush(heap, num // 3)
        return res


if __name__ == "__main__":
    s = Solution()
    nums = [1, 10, 3, 3, 3]
    res = s.maxKelements(nums, 3)
    print(res)
