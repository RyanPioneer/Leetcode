"""
Source: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Date: 2023/2/1
Skill:
Runtime: 594 ms, faster than 99.19%
Memory Usage: 16.7 MB, less than 95.80%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
