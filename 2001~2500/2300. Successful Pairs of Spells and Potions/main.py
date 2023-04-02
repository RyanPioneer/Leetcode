"""
Source: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
Date: 2023/4/2
Skill:
Runtime: 1236 ms, faster than 90.37%
Memory Usage: 37 MB, less than 69.69%
Time complexity:
Space complexity:
Constraints:
    1 <= spells[i], potions[i] <= 10^5
    1 <= success <= 10^10
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left
import functools


class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        sz = len(potions)
        for i in range(len(spells)):
            spells[i] = sz - bisect_left(potions, success / spells[i])
        return spells


if __name__ == "__main__":
    s = Solution()
