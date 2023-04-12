"""
Source: https://leetcode.com/problems/maximum-score-of-a-good-subarray/
Date: 2023/4/12
Skill:
Ref:
Runtime: 999 ms, faster than 99.28%
Memory Usage: 25 MB, less than 24.46%
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
    def maximumScore(self, nums: List[int], k: int) -> int:
        left, right, sz, res, min_value = k, k, len(nums), 0, nums[k]
        while left >= 0 or right < sz:
            while left >= 0 and nums[left] >= min_value:
                left -= 1
            while right < sz and nums[right] >= min_value:
                right += 1
            res = max(res, min_value * (right - left - 1))
            min_value = max(nums[left] if left >= 0 else -math.inf, nums[right] if right < sz else -math.inf)

        return res


if __name__ == "__main__":
    s = Solution()
    nums = [5, 5, 4, 5, 4, 1, 1, 1]
    k = 0
    res = s.maximumScore(nums, k)
