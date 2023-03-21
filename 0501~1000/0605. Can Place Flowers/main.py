"""
Source: https://leetcode.com/problems/can-place-flowers/
Date: 2023/3/20
Skill:
Runtime: 177 ms, faster than 34.25%
Memory Usage: 14.4 MB, less than 65.78%
Time complexity:
Space complexity:
Constraints:
    1 <= flowerbed.length <= 2 * 10^4
    0 <= n <= flowerbed.length
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        pos, sz = 0, len(flowerbed)

        def check_feasible(idx):
            if idx == 0:
                if sz == 1:
                    return flowerbed[idx] == 0
                else:
                    return flowerbed[idx] == 0 and flowerbed[idx + 1] == 0
            elif idx == sz-1:
                return flowerbed[idx] == 0 and flowerbed[idx - 1] == 0
            else:
                return flowerbed[idx] == 0 and flowerbed[idx - 1] == 0 and flowerbed[idx + 1] == 0

        while pos < sz and n > 0:
            if check_feasible(pos):
                flowerbed[pos] = 1
                n -= 1
            pos += 1

        return not n


if __name__ == "__main__":
    s = Solution()
