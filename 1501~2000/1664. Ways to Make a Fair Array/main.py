"""
Source: https://leetcode.com/problems/ways-to-make-a-fair-array/
Date: 2023/4/16
Skill:
Ref:
Runtime: 1389 ms, faster than 30.34%
Memory Usage: 21.4 MB, less than 31.62%
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
    def waysToMakeFair(self, nums: List[int]) -> int:
        sz, res, right_even, right_odd = len(nums), 0, 0, 0
        left_even, left_odd = [0 for _ in range(sz)], [0 for _ in range(sz)]
        for i in range(1, sz):
            left_even[i], left_odd[i] = left_even[i - 1], left_odd[i - 1]
            if i % 2:
                left_even[i] += nums[i - 1]
            else:
                left_odd[i] += nums[i - 1]

        if left_odd[sz - 1] == left_even[sz - 1]:
            res += 1
        for i in range(sz - 2, -1, -1):
            if i % 2:
                right_odd += nums[i + 1]
            else:
                right_even += nums[i + 1]
            if left_odd[i] + right_odd == left_even[i] + right_even:
                res += 1

        return res


if __name__ == "__main__":
    s = Solution()
