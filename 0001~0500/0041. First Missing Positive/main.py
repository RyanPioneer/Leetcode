"""
Source: https://leetcode.com/problems/first-missing-positive/description/
Date: 2023/2/2
Skill:
Runtime: 316 ms, faster than 54.8%
Memory Usage: 27.3 MB, less than 52.13%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 10^5
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            correct_pos = nums[i] - 1
            while i != correct_pos and 0 <= correct_pos < len(nums) and nums[i] != nums[correct_pos]:
                nums[i], nums[correct_pos] = nums[correct_pos], nums[i]
                correct_pos = nums[i] - 1

        for i in range(0, len(nums)):
            if nums[i] != i+1:
                return i+1
        return len(nums)+1

if __name__ == "__main__":
    s = Solution
    nums = [3,4,-1,1]
    res = s.firstMissingPositive(s, nums)