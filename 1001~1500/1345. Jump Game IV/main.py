"""
Source: https://leetcode.com/problems/jump-game-iv/
Date: 2023/3/5
Skill: BFS
Runtime: 721 ms, faster than 93.1%
Memory Usage: 27.5 MB, less than 92.68%
Time complexity:
Space complexity:
Constraints:
    1 <= arr.length <= 5 * 10^4
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest
from bisect import bisect_left, bisect_right
import heapq
import functools
from sortedcontainers import SortedList


class Solution:
    def minJumps(self, arr: List[int]) -> int:
        q, sz, step, my_map, visited = \
            deque([0]), len(arr), 0, defaultdict(list), [0 for _ in range(len(arr))]
        for i in range(sz):
            my_map[arr[i]].append(i)

        while q:
            num = len(q)
            for i in range(num):
                cur_idx = q.popleft()
                if cur_idx == sz - 1:
                    return step
                if not visited[cur_idx + 1]:
                    visited[cur_idx + 1] = 1
                    q.append(cur_idx + 1)
                if cur_idx > 0 and not visited[cur_idx - 1]:
                    visited[cur_idx - 1] = 1
                    q.append(cur_idx - 1)
                for next_pos in my_map[arr[cur_idx]]:
                    if not visited[next_pos]:
                        visited[next_pos] = 1
                        q.append(next_pos)

                my_map[arr[cur_idx]].clear()

            step += 1


if __name__ == "__main__":
    s = Solution()
