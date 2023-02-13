"""
Source: https://leetcode.com/problems/maximum-product-of-three-numbers/description/
Date: 2023/2/13
Skill:
Runtime: 269 ms, faster than 62.75%
Memory Usage: 15.2 MB, less than 60.22%
Time complexity:
Space complexity:
Constraints:
    3 <= nums.length <= 10^4
    -1000 <= nums[i] <= 1000
"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        max1, max2, max3, min1, min2 = -math.inf, -math.inf, -math.inf, math.inf, math.inf
        for num in nums:
            if num < min1:
                min1, min2 = num, min1
            elif num < min2:
                min2 = num
            if num > max1:
                max1, max2, max3 = num, max1, max2
            elif num > max2:
                max2, max3 = num, max2
            elif num > max3:
                max3 = num

        return max(max1 * max2 * max3, max1 * min1 * min2)


if __name__ == "__main__":
    s = Solution