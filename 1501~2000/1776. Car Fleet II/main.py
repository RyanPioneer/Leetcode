"""
Source: https://leetcode.com/problems/car-fleet-ii/
Date: 2023/7/4
Skill:
Ref:
Runtime: 1963 ms, faster than 58.88%
Memory Usage: 60.5 MB, less than 78.50%
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
    def getCollisionTimes(self, cars: List[List[int]]) -> List[float]:
        stack, res = [len(cars) - 1], [-1 for _ in range(len(cars))]
        for i in range(len(cars) - 2, -1, -1):
            while len(stack) > 0 and (cars[i][1] <= cars[stack[-1]][1] or
                    (res[stack[-1]] != -1 and (cars[stack[-1]][0] - cars[i][0]) /
                    (cars[i][1] - cars[stack[-1]][1]) > res[stack[-1]])):
                stack.pop()
            if len(stack) > 0:
                res[i] = (cars[stack[-1]][0] - cars[i][0]) / (cars[i][1] - cars[stack[-1]][1])
            stack.append(i)
        return res


if __name__ == "__main__":
    s = Solution()
