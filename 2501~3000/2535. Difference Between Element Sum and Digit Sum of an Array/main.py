"""
Source: https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/
Date: 2023/2/18
Skill:
Ref:
Runtime: 140 ms, faster than 67.41%
Memory Usage: 14.1 MB, less than 91.12%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 2000
    1 <= nums[i] <= 2000
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        element_sum, digit_sum = 0, 0
        for num in nums:
            element_sum += num
            while num > 0:
                digit_sum += num % 10
                num //= 10

        return abs(element_sum - digit_sum)


if __name__ == "__main__":
    s = Solution