"""
Source: https://rb.gy/7jmo7
Date: 2023/7/25
Skill:
Ref:
Runtime: 237 ms, faster than 90.70%
Memory Usage: 16.78 MB, less than 55.81%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def minimumTotalPrice(self, n: int, edges: List[List[int]], price: List[int], trips: List[List[int]]) -> int:
        if len(trips) == 1 and trips[0][0] == trips[0][1]:
            return price[trips[0][0]] // 2
        time, neighbors = [0 for _ in range(n)], [[] for _ in range(n)]
        for edge in edges:
            neighbors[edge[0]].append(edge[1])
            neighbors[edge[1]].append(edge[0])

        def dfs(src, parent, target):
            if src == target:
                time[src] += 1
                return True
            for neighbor in neighbors[src]:
                if neighbor == parent:
                    continue
                if dfs(neighbor, src, target):
                    time[src] += 1
                    return True
            return False

        for trip in trips:
            dfs(trip[0], -1, trip[1])

        dp = [[0, 0] for _ in range(n)]  # original, half

        def find_res(src, parent, can_choose):
            if dp[src][can_choose] != 0:
                return dp[src][can_choose]
            if not can_choose:
                dp[src][can_choose] += price[src] * time[src]
                for neighbor in neighbors[src]:
                    if neighbor == parent:
                        continue
                    dp[src][can_choose] += find_res(neighbor, src, not can_choose)
            else:
                option1, option2 = price[src] // 2 * time[src], price[src] * time[src]
                for neighbor in neighbors[src]:
                    if neighbor == parent:
                        continue
                    option1 += find_res(neighbor, src, not can_choose)
                if dp[src][not can_choose] != 0:
                    option2 = dp[src][not can_choose]
                else:
                    for neighbor in neighbors[src]:
                        if neighbor == parent:
                            continue
                        option2 += find_res(neighbor, src, can_choose)
                dp[src][can_choose] = min(option1, option2)
            return dp[src][can_choose]

        return find_res(0, -1, 1)


if __name__ == "__main__":
    s = Solution()
