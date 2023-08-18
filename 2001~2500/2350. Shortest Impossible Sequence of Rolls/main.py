"""
Source: https://rb.gy/nxbn7
Date: 2023/8/18
Skill:
Ref:
Runtime: 773 ms, faster than 80.21%
Memory Usage: 29.59 MB, less than 57.29%
Time complexity:
Space complexity:
Constraints:
    1 <= rolls.length <= 10 ** 5
    1 <= rolls[i] <= k <= 10 ** 5
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def shortestSequence(self, rolls: List[int], k: int) -> int:
        res, visited = 1, set()
        for roll in rolls:
            visited.add(roll)
            if len(visited) == k:
                res += 1
                visited.clear()
                # visited.add(roll)
        return res


if __name__ == "__main__":
    s = Solution()
