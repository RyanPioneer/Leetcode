"""
Source: https://leetcode.com/problems/asteroid-collision/
Date: 2023/7/3
Skill:
Ref:
Runtime: 107 ms, faster than 78.83%
Memory Usage: 17.6 MB, less than 63.52%
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
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        res = []
        for i in asteroids:
            if i > 0:
                res.append(i)
            else:
                while len(res) > 0 and 0 < res[-1] <= -i:
                    if res[-1] == -i:
                        break
                    res.pop()
                if len(res) == 0 or res[-1] < 0:
                    res.append(i)
                elif res[-1] == -i:
                    res.pop()
        return res


if __name__ == "__main__":
    s = Solution()
