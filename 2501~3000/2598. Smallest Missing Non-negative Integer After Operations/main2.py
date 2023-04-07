"""
Source: https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/
Date: 2023/4/7
Skill:
Ref:
Runtime: 935 ms, faster than 80.27%
Memory Usage: 28.8 MB, less than 85.3%
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


class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        cnt = [0 for _ in range(value)]
        for i in range(len(nums)):
            nums[i] %= value
            cnt[nums[i]] += 1
        min_freq, min_value = math.inf, math.inf
        for i in range(value):
            if cnt[i] == 0:
                return i
            if cnt[i] < min_freq:
                min_freq, min_value = cnt[i], i

        return min_freq * value + min_value


if __name__ == "__main__":
    s = Solution()
    nums = [3, 0, 3, 2, 4, 2, 1, 1, 0, 4]
    value = 5
    res = s.findSmallestInteger(nums, value)
    print(res)
