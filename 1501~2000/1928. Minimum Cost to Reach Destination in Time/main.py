"""
Source: https://rb.gy/w9v9b
Date: 2023/8/10
Skill:
Ref:
Runtime: 3204 ms, faster than 23.77%
Memory Usage: 40.6 MB, less than 21.31%
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
    def minCost(self, maxTime: int, edges: List[List[int]], passingFees: List[int]) -> int:
        neighbors, n = [defaultdict(int) for _ in range(len(passingFees))], len(passingFees)
        for edge in edges:
            if edge[0] in neighbors[edge[1]]:
                neighbors[edge[1]][edge[0]] = min(edge[2], neighbors[edge[1]][edge[0]])
            else:
                neighbors[edge[1]][edge[0]] = edge[2]
            if edge[1] in neighbors[edge[0]]:
                neighbors[edge[0]][edge[1]] = min(edge[2], neighbors[edge[0]][edge[1]])
            else:
                neighbors[edge[0]][edge[1]] = edge[2]

        earlist_time = [sys.maxsize for _ in range(n)]
        dp = [[sys.maxsize for _ in range(maxTime + 1)] for _ in range(n)]
        dp[0][0], earlist_time[0] = passingFees[0], 0
        q = deque([[0, 0]])
        while q:
            [pos, time] = q.popleft()
            for next_pos, cost in neighbors[pos].items():
                if time + cost > maxTime:
                    continue
                if dp[pos][time] + passingFees[next_pos] > dp[next_pos][time + cost]:
                    continue
                if time + cost > earlist_time[next_pos] and dp[next_pos][earlist_time[next_pos]] \
                        < dp[pos][time] + passingFees[next_pos]:
                    continue
                if dp[pos][time] + passingFees[next_pos] >= dp[next_pos][time + cost]:
                    continue
                dp[next_pos][time + cost] = min(dp[next_pos][time + cost], dp[pos][time] + passingFees[next_pos])
                q.append([next_pos, time + cost])
                earlist_time[next_pos] = min(earlist_time[next_pos], time + cost)

        res = min(dp[-1])
        return res if res != sys.maxsize else -1


if __name__ == "__main__":
    s = Solution()
