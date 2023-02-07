"""
Source: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/
Date: 2023/2/7
Skill:
Runtime: 946 ms, faster than 58.94%
Memory Usage: 28.2 MB, less than 89.40%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^6
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        max_num, res, idx, sz = max(nums), 1, 0, len(nums)
        while idx < sz:
            if nums[idx] == max_num:
                head = idx
                while idx+1 < sz and nums[idx+1] == max_num:
                    idx += 1
                res = max(res, idx-head+1)

            idx += 1

        return res


if __name__ == "__main__":
    s = Solution