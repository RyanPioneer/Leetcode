"""
Source: https://rb.gy/xe9di
Date: 2023/7/27
Skill:
Ref:
Runtime: 82 ms, faster than 77.58%
Memory Usage: 16.18 MB, less than 97.07%
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
    def countKDifference(self, nums: List[int], k: int) -> int:
        sz, res, right = len(nums), 0, 0
        nums.sort()
        for i in range(sz):
            while right < sz and nums[right] - nums[i] < k:
                right += 1
            if right < sz and nums[right] - nums[i] == k:
                r = right
                while r < sz and nums[r] - nums[i] == k:
                    r += 1
                    res += 1
            if right == sz:
                break
        return res


if __name__ == "__main__":
    s = Solution()
