"""
Source: https://rb.gy/zgkhp
Date: 2023/7/16
Skill:
Ref:
Runtime: 941 ms, faster than 23.42%
Memory Usage: 24.47 MB, less than 35.44%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def smallestSufficientTeam(self, req_skills: List[str], people: List[List[str]]) -> List[int]:
        sz = len(req_skills)
        dp, res = [sys.maxsize for _ in range(1 << sz)], [[] for _ in range(1 << sz)]
        dp[0] = 0
        skill2bits = defaultdict(int)
        for i in range(sz):
            skill2bits[req_skills[i]] = 1 << i
        for i in range(len(people)):
            dp2 = dp
            skill_bits = 0
            for skill in people[i]:
                skill_bits += skill2bits[skill]
            for j in range(1 << sz):
                new_skill = j | skill_bits
                if dp2[new_skill] > dp[j] + 1:
                    dp2[new_skill] = dp[j] + 1
                    res[new_skill] = res[j].copy()
                    res[new_skill].append(i)
            dp = dp2

        return res[(1 << sz) - 1]


if __name__ == "__main__":
    s = Solution()

