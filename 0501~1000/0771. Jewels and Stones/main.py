"""
Source: https://leetcode.com/problems/jewels-and-stones/
Date: 2023/2/17
Skill:
Runtime: 30 ms, faster than 82.9%
Memory Usage: 13.8 MB, less than 50.61%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        jewels, res = set(jewels), 0
        for stone in stones:
            if stone in jewels:
                res += 1

        return res


if __name__ == "__main__":
    s = Solution