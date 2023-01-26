"""
Source: https://leetcode.com/problems/missing-number/
Date: 2023/1/26
Skill:
Runtime: 129 ms, faster than 94.47%
Memory Usage: 15.2 MB, less than 72.97%
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
    def missingNumber(self, nums: List[int]) -> int:
        return len(nums)*(len(nums)+1)//2-sum(nums)