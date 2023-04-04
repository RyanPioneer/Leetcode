"""
Source: https://leetcode.com/problems/stone-game-vi/
Date: 2023/4/4
Skill:
Ref:
Runtime: 1291 ms, faster than 43.81%
Memory Usage: 28.1 MB, less than 42.86%
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
    def stoneGameVI(self, aliceValues: List[int], bobValues: List[int]) -> int:
        sz, total_values = len(aliceValues), []
        for i in range(sz):
            total_values.append((aliceValues[i] + bobValues[i], i))
        total_values.sort(reverse=True)
        alice_total, bob_total = 0, 0
        for i in range(sz):
            if i % 2 == 0:
                alice_total += aliceValues[total_values[i][1]]
            else:
                bob_total += bobValues[total_values[i][1]]

        if alice_total > bob_total:
            return 1
        elif alice_total < bob_total:
            return -1
        else:
            return 0


if __name__ == "__main__":
    s = Solution()
