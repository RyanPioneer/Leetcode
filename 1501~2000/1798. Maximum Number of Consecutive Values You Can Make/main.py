"""
Source: https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/
Date: 2023/3/27
Skill:
Runtime: 752 ms, faster than 68.57%
Memory Usage: 19.8 MB, less than 14.29%
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


class Solution:
    def getMaximumConsecutive(self, coins: List[int]) -> int:
        coins.sort()
        max_num = 0
        for coin in coins:
            if coin > max_num + 1:
                return max_num + 1
            max_num += coin

        return max_num + 1


if __name__ == "__main__":
    s = Solution()
