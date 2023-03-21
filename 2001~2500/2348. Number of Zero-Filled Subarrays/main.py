"""
Source: https://leetcode.com/problems/number-of-zero-filled-subarrays/
Date: 2023/3/21
Skill:
Runtime: 1054 ms, faster than 91.87%
Memory Usage: 24.7 MB, less than 30.39%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        my_dict, num, sz, res = defaultdict(int), 0, len(nums), 0
        for i in range(sz):
            if nums[i] == 0:
                num += 1
            else:
                if num != 0:
                    my_dict[num] += 1
                num = 0

        if num != 0:
            my_dict[num] += 1

        for key, value in my_dict.items():
            res += value * (key * (key + 1)) // 2

        return res


if __name__ == "__main__":
    s = Solution()
    nums = [0, 0, 0, 2, 0, 0]
    res = s.zeroFilledSubarray(nums)
