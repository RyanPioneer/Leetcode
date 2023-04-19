"""
Source: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
Date: 2023/4/18
Skill:
Ref:
Runtime: 1184 ms, faster than 50.27%
Memory Usage: 22.7 MB, less than 99.22%
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
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        sz, res = len(colors), 0
        for start in range(sz - 1):
            if colors[start] == colors[start + 1]:
                res += min(neededTime[start], neededTime[start + 1])
                neededTime[start + 1] = max(neededTime[start], neededTime[start + 1])

        return res


if __name__ == "__main__":
    s = Solution()
