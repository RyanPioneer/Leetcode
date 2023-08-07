"""
Source: https://rb.gy/zaftw
Date: 2023/8/7
Skill:
Ref:
Runtime: 60 ms, faster than 69.50%
Memory Usage: 16.38 MB, less than 84.40%
Time complexity:
Space complexity:
Constraints:
    1 <= m, n <= 3
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def minFlips(self, mat: List[List[int]]) -> int:
        m, n, state, target, visited = len(mat), len(mat[0]), "", "", defaultdict(int)
        for i in range(m):
            for j in range(n):
                state += str(mat[i][j])
                target += "0"

        visited[state], q, res = 1, deque([state]), -1
        dirs = [0, 1, 0, -1, 0]
        # flip = [False for _ in range(m * n)]

        def check_feasible(a, b):
            return 0 <= a < m and 0 <= b < n

        def flip_char(s):
            return "0" if s == "1" else "1"

        while q:
            sz = len(q)
            res += 1
            for _ in range(sz):
                cur_state = q.popleft()
                if cur_state == target:
                    return res
                for i in range(m * n):
                    # if flip[i]:
                    #     continue
                    # flip[i] = True
                    x, y, new_state = i // n, i % n, cur_state[:i] + flip_char(cur_state[i]) + cur_state[i + 1:]
                    for j in range(4):
                        next_x, next_y = x + dirs[j], y + dirs[j + 1]
                        if check_feasible(next_x, next_y):
                            pos = next_x * n + next_y
                            new_state = new_state[:pos] + flip_char(new_state[pos]) + new_state[pos + 1:]
                    if new_state not in visited:
                        if new_state == target:
                            return res + 1
                        visited[new_state] = 1
                        q.append(new_state)

        return -1


if __name__ == "__main__":
    s = Solution()
    mat = [[0, 0], [0, 1]]
    res = s.minFlips(mat)
    print(res)
