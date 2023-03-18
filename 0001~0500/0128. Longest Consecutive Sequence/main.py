"""
Source: https://leetcode.com/problems/longest-consecutive-sequence/
Date: 2023/3/17
Skill:
Runtime: 2577 ms, faster than 12.30%
Memory Usage: 28.9 MB, less than 57.2%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        myset, res = set(nums), 0
        for num in nums:
            if num-1 not in myset:
                time = 1
                while num+1 in myset:
                    num += 1
                    time += 1
                res = max(res, time)

        return res


if __name__ == "__main__":
    s = Solution()
