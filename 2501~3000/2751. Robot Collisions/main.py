"""
Source: https://rb.gy/di0sp
Date: 2023/7/8
Skill:
Ref:
Runtime: TLE
Memory Usage:
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
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        order, res, robots = [i for i in range(len(positions))], [], []
        order.sort(key=lambda x: positions[x])
        for i in order:
            if directions[i] == "L":
                flag = True
                while len(robots) > 0 and directions[robots[-1]] == "R":
                    if res[-1] > healths[i]:
                        res[-1] -= 1
                        flag = False
                        break
                    elif res[-1] < healths[i]:
                        res.pop()
                        robots.pop()
                        healths[i] -= 1
                    else:
                        res.pop()
                        robots.pop()
                        flag = False
                        break
                if flag:
                    res.append(healths[i])
                    robots.append(i)
            else:
                res.append(healths[i])
                robots.append(i)
        pos = []
        for i in range(len(positions)):
            if i in robots:
                for j in range(len(robots)):
                    if robots[j] == i:
                        pos.append(res[j])
                        break
        return pos


if __name__ == "__main__":
    s = Solution()

