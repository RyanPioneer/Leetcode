"""
Source: https://leetcode.com/problems/largest-number/
Date: 2023/1/31
Skill:
Runtime: 30 ms, faster than 98.93%
Memory Usage: 13.8 MB, less than 61.3%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 100
    0 <= nums[i] <= 10^9
"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Num(str):
    def __lt__(self, other):
        return self+other > other+self

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        res = "".join(sorted(map(str, nums), key=Num))
        return "0" if res[0] == "0" else res