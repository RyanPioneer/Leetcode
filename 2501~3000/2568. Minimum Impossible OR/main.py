"""
Source: https://leetcode.com/problems/minimum-impossible-or/
Date: 2023/3/27
Skill:
Runtime: 498 ms, faster than 28.61%
Memory Usage: 28.1 MB, less than 65.61%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 10^5
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def minImpossibleOR(self, nums: List[int]) -> int:
        nums.sort()
        max_num = 0
        for num in nums:
            if num > max_num + 1:
                return max_num + 1
            max_num |= num

        return max_num + 1


if __name__ == "__main__":
    s = Solution()
