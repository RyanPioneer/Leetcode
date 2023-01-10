"""
Source: https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/
Date: 2023/1/9
Skill:
Ref:
Runtime: 2052 ms, faster than 89.77%
Memory Usage: 55.4 MB, less than 99.1%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import defaultdict, deque
import math

class Solution:
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        if not roads: return 0
        n = len(roads)

        inDegrees = [0] * (n + 1)
        G = defaultdict(list)
        for u, v in roads:
            G[u].append(v)
            inDegrees[v] += 1
            G[v].append(u)
            inDegrees[u] += 1

        queue = deque()
        for i, deg in enumerate(inDegrees):
            if deg == 1 and i != 0:  # !!! if we got a linked-list we don't count capital
                queue.append(i)  # city
        caps = [1] * (n + 1)

        cnt = 0
        while queue:
            node = queue.popleft()
            cnt += math.ceil(caps[node] / seats)
            for nxt in G[node]:
                caps[nxt] += caps[node]
                inDegrees[nxt] -= 1
                if inDegrees[nxt] == 1 and nxt != 0:
                    queue.append(nxt)

        return cnt