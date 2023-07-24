"""
Source: https://rb.gy/all6g
Date: 2023/7/24
Skill:
Ref:
Runtime: 1874 ms, faster than 50.00%
Memory Usage: 29.02 MB, less than 92.31%
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
    def componentValue(self, nums: List[int], edges: List[List[int]]) -> int:
        total, degree, neighbors, sums, sz = sum(nums), [0 for _ in range(len(nums))], \
            defaultdict(list), [], len(nums)
        if sz == 1:
            return 0
        for edge in edges:
            degree[edge[0]] += 1
            degree[edge[1]] += 1
            neighbors[edge[0]].append(edge[1])
            neighbors[edge[1]].append(edge[0])
        for i in range(1, math.isqrt(total) + 1):
            if total % i == 0:
                sums.append(i)
                sums.append(total // i)

        sums.sort()
        for num in sums:
            cur_num = nums.copy()
            cur_deg = degree.copy()
            q, visited, flag = deque(), [0 for _ in range(sz)], True
            for i in range(sz):
                if cur_deg[i] == 1:
                    q.append(i)
                    visited[i] = 1
            while q:
                cur_pos = q.popleft()
                if cur_num[cur_pos] > num:
                    flag = False
                    break
                if cur_num[cur_pos] == num:
                    cur_num[cur_pos] = 0
                for next_pos in neighbors[cur_pos]:
                    if not visited[next_pos]:
                        cur_deg[next_pos] -= 1
                        cur_num[next_pos] += cur_num[cur_pos]
                        if cur_deg[next_pos] == 1:
                            q.append(next_pos)
                            visited[next_pos] = 1

            if flag:
                return total // num - 1


if __name__ == "__main__":
    s = Solution()
