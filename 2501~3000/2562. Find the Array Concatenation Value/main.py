"""
Source: https://leetcode.com/problems/find-the-array-concatenation-value/
Date: 2023/2/13
Skill:
Runtime: 63 ms, faster than 55.56%
Memory Usage: 13.9 MB, less than 72.22%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 1000
    1 <= nums[i] <= 10^4
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        res, left, right = 0, 0, len(nums)-1
        while left < right:
            res += int(str(nums[left]) + str(nums[right]))
            left += 1
            right -= 1

        return res if left != right else res + nums[left]


if __name__ == "__main__":
    s = Solution