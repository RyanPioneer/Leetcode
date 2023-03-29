"""
Source: https://leetcode.com/problems/split-array-largest-sum/
Date: 2023/3/29
Skill: Binary search
Runtime: 45 ms, faster than 40.40%
Memory Usage: 14 MB, less than 66.18%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 1000
    0 <= nums[i] <= 10^6
    1 <= k <= min(50, nums.length)
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        low, high, sz = max(nums), sum(nums), len(nums)

        def check_feasible(val):
            pos, num, total = 0, 0, 0
            while pos < sz and num < k:
                if nums[pos] + total <= val:
                    total += nums[pos]
                else:
                    total = nums[pos]
                    num += 1
                pos += 1

            return True if pos == sz and num < k else False

        while low < high:
            mid = (low + high) // 2
            if check_feasible(mid):
                high = mid
            else:
                low = mid + 1

        return low


if __name__ == "__main__":
    s = Solution()
