"""
Source: https://leetcode.com/problems/distribute-money-to-maximum-children/
Date: 2023/3/22
Skill:
Runtime: 51 ms, faster than 23.73%
Memory Usage: 13.9 MB, less than 59.84%
Time complexity:
Space complexity:
Constraints:
    1 <= money <= 200
    2 <= children <= 30
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def distMoney(self, money: int, children: int) -> int:
        if money < children or (children == 1 and money == 4):
            return -1
        money -= children
        res = 0
        for _ in range(children - 1):
            if money < 7:
                break
            money -= 7
            res += 1
        if money == 7:
            res += 1
        if money == 3 and res == children - 1:
            res -= 1

        return res


if __name__ == "__main__":
    s = Solution()
