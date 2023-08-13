"""
Source: https://rb.gy/6xmmf
Date: 2023/8/13
Skill:
Ref:
Runtime: 182 ms, faster than 100%
Memory Usage: 16.3 MB, less than 66.67%
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
    def maxSum(self, nums: List[int]) -> int:
        sz, res, max_digit = len(nums), -1, []

        def get_max_digit(num):
            d = 1
            while num > 0:
                d = max(d, num % 10)
                num //= 10
            return d

        for i in range(sz):
            max_digit.append(get_max_digit(nums[i]))

        for i in range(sz - 1):
            for j in range(i + 1, sz):
                if max_digit[i] == max_digit[j]:
                    res = max(res, nums[i] + nums[j])

        return res


if __name__ == "__main__":
    s = Solution()
