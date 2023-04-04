"""
Source: https://leetcode.com/problems/stone-game/
Date: 2023/4/4
Skill:
Ref: https://rb.gy/j5lw
Runtime: 32 ms, faster than 90.15%
Memory Usage: 13.9 MB, less than 74.83%
Time complexity:
Space complexity:
Constraints:
    2 <= piles.length <= 500
    piles.length is even.
    1 <= piles[i] <= 500
    sum(piles[i]) is odd.
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        return True


if __name__ == "__main__":
    s = Solution()
