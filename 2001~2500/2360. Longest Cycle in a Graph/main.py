"""
Source: https://leetcode.com/problems/longest-cycle-in-a-graph/
Date: 2023/3/26
Skill:
Runtime: 1567 ms, faster than 33.34%
Memory Usage: 41.1 MB, less than 66.98%
Time complexity:
Space complexity:
Constraints:
    2 <= edges.length <= 10^5
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def longestCycle(self, edges: List[int]) -> int:
        visited, time, res, sz = [[False, -1, -1] for _ in range(len(edges))], 0, -1, len(edges)
        for i in range(sz):
            if not visited[i][0] and edges[i] != -1:
                cur_pos = i
                next_pos = edges[i]
                visited[cur_pos] = [True, time, 0]
                while next_pos != -1:
                    if visited[next_pos][0]:
                        if visited[next_pos][1] == time:
                            res = max(res, visited[cur_pos][2] - visited[next_pos][2] + 1)
                        break
                    else:
                        visited[next_pos] = [True, time, visited[cur_pos][2] + 1]
                        cur_pos = next_pos
                        next_pos = edges[next_pos]
                time += 1

        return res


if __name__ == "__main__":
    s = Solution()
    edges = [3, 3, 4, 2, 3]
    res = s.longestCycle(edges)
