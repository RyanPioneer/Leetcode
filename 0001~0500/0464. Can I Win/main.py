"""
Source: https://rb.gy/0v862
Date: 2023/7/29
Skill:
Ref:
Runtime: 3601 ms, faster than 41.90%
Memory Usage: 324.9 MB, less than 5.05%
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
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        if maxChoosableInteger * (1 + maxChoosableInteger) // 2 < desiredTotal:
            return False
        visited = defaultdict(bool)

        def dfs(cur_state, target):
            if cur_state in visited:
                return visited[cur_state]
            cur_state_list = list(cur_state)
            for i in range(maxChoosableInteger):
                if cur_state_list[i] == 1:
                    continue
                if i + 1 >= target:
                    visited[cur_state] = True
                    return visited[cur_state]
                else:
                    next_state = list(cur_state)
                    next_state[i] = 1
                    if not dfs(tuple(next_state), target - (i + 1)):
                        visited[cur_state] = True
                        return visited[cur_state]
            visited[cur_state] = False
            return visited[cur_state]

        return dfs(tuple([0 for _ in range(maxChoosableInteger)]), desiredTotal)


if __name__ == "__main__":
    s = Solution()
    res = s.canIWin(10, 11)
    print(res)
