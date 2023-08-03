"""
Source: https://rb.gy/6u4v5
Date: 2023/8/3
Skill:
Ref:
Runtime: 1893 ms, faster than 24.33%
Memory Usage: 90.38 MB, less than 26.84%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def canMeasureWater(self, jug1Capacity: int, jug2Capacity: int, targetCapacity: int) -> bool:
        if jug1Capacity + jug2Capacity < targetCapacity:
            return False
        if jug1Capacity == targetCapacity or jug2Capacity == targetCapacity or jug1Capacity + jug2Capacity == targetCapacity:
            return True
        state = set()
        state.add((0, 0))
        q = deque([[0, 0]])
        while q:
            cap = q.popleft()
            if cap[0] == targetCapacity or cap[1] == targetCapacity or cap[0] + cap[1] == targetCapacity:
                return True
            if cap[0] < jug1Capacity and (jug1Capacity, cap[1]) not in state:
                q.append([jug1Capacity, cap[1]])
                state.add((jug1Capacity, cap[1]))
            if cap[1] < jug2Capacity and (cap[0], jug2Capacity) not in state:
                q.append([cap[0], jug2Capacity])
                state.add((cap[0], jug2Capacity))
            if cap[0] > 0 and (0, cap[1]) not in state:
                q.append([0, cap[1]])
                state.add((0, cap[1]))
            if cap[1] > 0 and (cap[0], 0) not in state:
                q.append([cap[0], 0])
                state.add((cap[0], 0))
            if cap[0] > 0:
                water = min(cap[0], jug2Capacity - cap[1])
                if (cap[0] - water, cap[1] + water) not in state:
                    q.append([cap[0] - water, cap[1] + water])
                    state.add((cap[0] - water, cap[1] + water))
            if cap[1] > 0:
                water = min(cap[1], jug1Capacity - cap[0])
                if (cap[0] + water, cap[1] - water) not in state:
                    q.append([cap[0] + water, cap[1] - water])
                    state.add((cap[0] + water, cap[1] - water))

        return False


if __name__ == "__main__":
    s = Solution()
