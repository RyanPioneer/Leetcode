"""
Source: https://leetcode.com/problems/matchsticks-to-square/
Date: 2023/4/15
Skill:
Ref:
Runtime: 64 ms, faster than 98.53%
Memory Usage: 13.9 MB, less than 75.64%
Time complexity:
Space complexity:
Constraints:
    1 <= matchsticks.length <= 15
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        sz, edge = len(matchsticks), sum(matchsticks) // 4
        if sz < 4 or edge * 4 != sum(matchsticks):
            return False
        used = [False for _ in range(sz)]
        matchsticks.sort(reverse=True)

        def dfs(cur_idx, group_num, cur_sum):
            if group_num == 4:
                return True
            if cur_sum == edge:
                return dfs(0, group_num + 1, 0)
            if cur_sum > edge or cur_idx == sz:
                return False

            last_num = -1
            for i in range(cur_idx, sz):
                if used[i] or matchsticks[i] == last_num:
                    continue
                used[i] = True
                if dfs(i + 1, group_num, cur_sum + matchsticks[i]):
                    return True
                used[i] = False
                last_num = matchsticks[i]

            return False

        return dfs(0, 0, 0)


if __name__ == "__main__":
    s = Solution()
    arr = [5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3]
    print(s.makesquare(arr))
