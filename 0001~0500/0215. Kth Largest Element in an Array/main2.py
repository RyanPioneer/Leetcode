"""
Source: https://leetcode.com/problems/kth-largest-element-in-an-array/
Date: 2023/8/14
Skill: Binary search
Runtime: 530 ms, faster than 53.26%
Memory Usage: 29.56 MB, less than 55.40%
Time complexity:
Space complexity:
Constraints:
    1 <= k <= nums.length <= 10^5
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
import bisect
import heapq
import functools


class Solution:
    def findKthLargest(self, nums: List[int], t: int) -> int:
        lo, hi = min(nums), max(nums)
        while lo < hi:
            mid, cnt = (lo + hi) // 2, 0
            for num in nums:
                if num > mid:
                    cnt += 1
            if cnt >= t:
                lo = mid + 1
            else:
                hi = mid
        return lo


if __name__ == "__main__":
    s = Solution()
    nums, k = [3, 2, 1, 5, 6, 4], 2
    res = s.findKthLargest(nums, k)
    print(res)
