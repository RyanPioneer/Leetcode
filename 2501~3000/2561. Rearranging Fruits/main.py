"""
Source: https://leetcode.com/problems/rearranging-fruits/
Date: 2023/2/16
Skill:
Runtime: 867 ms, faster than 63.45%
Memory Usage: 37.4 MB, less than 84.24%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
        my_dict, nums, min_num, res = defaultdict(int), [], math.inf, 0
        for i in basket1:
            my_dict[i] += 1
            min_num = min(min_num, i)
        for i in basket2:
            my_dict[i] -= 1
            min_num = min(min_num, i)

        for key, val in my_dict.items():
            if val % 2 == 1:
                return -1
            for i in range(abs(val) // 2):
                nums.append(key)

        nums.sort()
        for i in range(len(nums) // 2):
            res += min(nums[i], 2 * min_num)

        return res


if __name__ == "__main__":
    s = Solution