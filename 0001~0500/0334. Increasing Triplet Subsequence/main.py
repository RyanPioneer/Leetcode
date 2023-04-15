"""
Source: https://leetcode.com/problems/increasing-triplet-subsequence/
Date: 2023/4/15
Skill:
Ref:
Runtime: 1300 ms, faster than 15.95%
Memory Usage: 30 MB, less than 74.44%
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
    def increasingTriplet(self, nums: List[int]) -> bool:
        pre_smaller, suf_bigger, sz = [False for _ in range(len(nums))], \
            [False for _ in range(len(nums))], len(nums)
        min_val, max_val = nums[0], nums[sz - 1]
        for i in range(1, sz):
            if min_val < nums[i]:
                pre_smaller[i] = True
            else:
                min_val = nums[i]
            if max_val > nums[sz - i - 1]:
                suf_bigger[sz - i - 1] = True
            else:
                max_val = nums[sz - i - 1]

        for i in range(1, sz - 1):
            if pre_smaller[i] and suf_bigger[i]:
                return True
        return False


if __name__ == "__main__":
    s = Solution()
