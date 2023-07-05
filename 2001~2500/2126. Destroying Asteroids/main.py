"""
Source: https://leetcode.com/problems/destroying-asteroids/
Date: 2023/7/3
Skill:
Ref:
Runtime: 1057 ms, faster than 89.35%
Memory Usage: 30.2 MB, less than 43.79%
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
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids.sort()
        for i in asteroids:
            if i > mass:
                return False
            mass += i
        return True


if __name__ == "__main__":
    s = Solution()
