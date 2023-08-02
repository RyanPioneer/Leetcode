"""
Source: https://rb.gy/ge4wr
Date: 2023/8/2
Skill:
Ref:
Runtime: 738 ms, faster than 100.00%
Memory Usage: 35.03 MB, less than 57.00%
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
    def makeSimilar(self, nums: List[int], target: List[int]) -> int:
        nums.sort()
        target.sort()
        even_nums, odd_nums, sz, res = [], [], len(nums), 0
        even_target, odd_target = [], []
        for i in range(sz):
            if nums[i] % 2 == 0:
                even_nums.append(nums[i])
            else:
                odd_nums.append(nums[i])
            if target[i] % 2 == 0:
                even_target.append(target[i])
            else:
                odd_target.append(target[i])

        for i in range(len(even_nums)):
            if even_nums[i] > even_target[i]:
                res += (even_nums[i] - even_target[i]) // 2

        for i in range(len(odd_nums)):
            if odd_nums[i] > odd_target[i]:
                res += (odd_nums[i] - odd_target[i])

        return res


if __name__ == "__main__":
    s = Solution
