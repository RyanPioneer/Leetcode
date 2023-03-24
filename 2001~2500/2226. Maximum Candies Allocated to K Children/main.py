"""
Source: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
Date: 2023/3/24
Skill:
Runtime: 1029 ms, faster than 91.70%
Memory Usage: 27.3 MB, less than 60.7%
Time complexity:
Space complexity:
Constraints:
    1 <= candies.length <= 10^5
    1 <= k <= 10^12
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        if sum(candies) < k:
            return 0
        low, high = 1, sum(candies) // k
        while low < high:
            mid = (low + high + 1) // 2
            num = 0
            for candy in candies:
                num += candy // mid
            if num < k:
                high = mid - 1
            else:
                low = mid

        return low


if __name__ == "__main__":
    s = Solution()
    candies = [5, 8, 6]
    k = 3
    res = s.maximumCandies(candies, k)
