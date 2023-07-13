"""
Source: https://rb.gy/8jen2
Date: 2023/7/12
Skill: Topology sort
Ref:
Runtime: 859 ms, faster than 64.34%
Memory Usage: 25 MB, less than 41.86%
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
    def buildMatrix(self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]) -> List[List[int]]:
        def topology_sort(arr):
            in_degree, adj_list = [0 for _ in range(k)], [[] for _ in range(k)]
            for i in arr:
                in_degree[i[1]-1] += 1
                adj_list[i[0]-1].append(i[1]-1)
            q, res = deque(), []
            for i in range(k):
                if in_degree[i] == 0:
                    q.append(i)
            while q:
                cur_idx = q.popleft()
                res.append(cur_idx)
                for next in adj_list[cur_idx]:
                    in_degree[next] -= 1
                    if in_degree[next] == 0:
                        q.append(next)
            return res

        row_order, col_order = topology_sort(rowConditions), topology_sort(colConditions)
        if len(row_order) < k or len(col_order) < k:
            return []
        res = [[0 for _ in range(k)] for _ in range(k)]
        pos = [[0, 0] for _ in range(k)]
        for i in range(k):
            pos[row_order[i]][0] = i
            pos[col_order[i]][1] = i
        for i in range(k):
            res[pos[i][0]][pos[i][1]] = i + 1
        return res


if __name__ == "__main__":
    s = Solution()
