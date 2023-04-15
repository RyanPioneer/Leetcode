"""
Source: https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/
Date: 2023/4/15
Skill: Backtracking
Ref:
Runtime: 41 ms, faster than 82.86%
Memory Usage: 13.9 MB, less than 25.71%
Time complexity:
Space complexity:
Constraints:
    1 <= n <= 20
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        res, used = [-1 for _ in range(2 * n - 1)], [False for _ in range(n)]

        def dfs(x):
            if x == 2 * n - 1:
                return True
            if res[x] != -1:
                return dfs(x + 1)
            for num in range(n, 0, -1):
                if used[num - 1]:
                    continue
                if num != 1 and (x + num >= 2 * n - 1 or res[x + num] != -1):
                    continue
                used[num - 1] = True
                res[x] = num
                if num != 1:
                    res[x + num] = num
                if dfs(x + 1):
                    return True
                used[num - 1] = False
                res[x] = -1
                if num != 1:
                    res[x + num] = -1

            return False

        dfs(0)
        return res


if __name__ == "__main__":
    s = Solution()
