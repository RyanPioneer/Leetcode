"""
Source: https://leetcode.com/problems/car-fleet/
Date: 2023/7/3
Skill:
Ref:
Runtime: 831 ms, faster than 98.74%
Memory Usage: 33.4 MB, less than 99.83%
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
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = [i for i in range(len(position))]
        cars.sort(key=lambda x: position[x], reverse=True)
        res, prev_pos, prev_speed = 1, position[cars[0]], speed[cars[0]]
        for i in range(1, len(cars)):
            cur_pos, cur_speed = position[cars[i]], speed[cars[i]]
            if (target - prev_pos) / prev_speed * cur_speed < target - cur_pos:
                res += 1
                prev_pos, prev_speed = cur_pos, cur_speed

        return res


if __name__ == "__main__":
    s = Solution()
