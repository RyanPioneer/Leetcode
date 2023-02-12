"""
Source: https://leetcode.com/problems/separate-the-digits-in-an-array/
Date: 2023/2/12
Skill:
Runtime: 77 ms, faster than 58.82%
Memory Usage: 14.5 MB, less than 66.62%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 1000
    1 <= nums[i] <= 10^5
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        res = []
        for num in nums:
            num = str(num)
            for c in num:
                res.append(int(c))

        return res


if __name__ == "__main__":
    s = Solution