"""
Source: https://leetcode.com/problems/grumpy-bookstore-owner/
Date: 2023/4/19
Skill:
Ref:
Runtime: 281 ms, faster than 84.4%
Memory Usage: 16.4 MB, less than 76.81%
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
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        res, cur_sum, sz, satisfied_number = 0, 0, len(customers), 0
        for i in range(minutes):
            if grumpy[i]:
                cur_sum += customers[i]
            else:
                satisfied_number += customers[i]

        res = cur_sum
        for i in range(minutes, sz):
            if grumpy[i]:
                cur_sum += customers[i]
            else:
                satisfied_number += customers[i]
            if grumpy[i - minutes]:
                cur_sum -= customers[i - minutes]
            res = max(res, cur_sum)

        return res + satisfied_number


if __name__ == "__main__":
    s = Solution()
