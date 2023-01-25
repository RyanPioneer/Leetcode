"""
Source: https://leetcode.com/problems/accounts-merge/
Date: 2023/1/24
Skill:
Runtime: 129 ms, faster than 66.32%
Memory Usage: 13.9 MB, less than 67.56%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List
from collections import deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools

from collections import deque

class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
