"""
Source: https://leetcode.com/problems/contiguous-array/
Date: 2023/2/8
Skill: Prefix Sum
Runtime: 854 ms, faster than 80.31%
Memory Usage: 19.5 MB, less than 36.71%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 10^5
    nums[i] is either 0 or 1.
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        res, my_map, cur_sum = 0, defaultdict(), 0
        my_map[0] = -1
        for i in range(len(nums)):
            cur_sum = cur_sum + 1 if nums[i] == 1 else cur_sum - 1
            if cur_sum in my_map:
                res = max(res, i-my_map[cur_sum])
            else:
                my_map[cur_sum] = i

        return res

if __name__ == "__main__":
    s = Solution