"""
Source: https://leetcode.com/problems/find-the-town-judge/
Date: 2023/1/23
Skill:
Runtime: 730 ms, faster than 92.11%
Memory Usage: 19 MB, less than 59.7%
Time complexity:
Space complexity:
Constraints:

"""
import math
from typing import List
from collections import defaultdict, deque
from functools import lru_cache, cache

class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        count = [0 for _ in range(n)]

        for i in trust:
            count[i[1]-1] += 1
            count[i[0]-1] -= 1

        for i in range(n):
            if count[i] == n-1:
                return i+1

        return -1