"""
Source: https://leetcode.com/problems/squares-of-a-sorted-array/
Date: 2023/3/18
Skill: Two Pointer
Runtime: 222 ms, faster than 73.41%
Memory Usage: 16.1 MB, less than 77.1%
Time complexity:
Space complexity:
Constraints:
    Find an O(n) solution
"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        left, right, res, cur_idx = 0, len(nums) - 1, \
            [i for i in range(len(nums))], len(nums) - 1
        while left <= right:
            if abs(nums[left]) >= abs(nums[right]):
                res[cur_idx] = (nums[left] * nums[left])
                left += 1
            else:
                res[cur_idx] = (nums[right] * nums[right])
                right -= 1

            cur_idx -= 1

        return res


if __name__ == "__main__":
    s = Solution()
