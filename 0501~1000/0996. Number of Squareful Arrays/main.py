"""
Source: https://leetcode.com/problems/number-of-squareful-arrays/
Date: 2023/4/16
Skill: DFS
Ref:
Runtime: 33 ms, faster than 78.35%
Memory Usage: 14 MB, less than 32.47%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length <= 12
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def numSquarefulPerms(self, nums: List[int]) -> int:
        sz, res = len(nums), 0
        nums.sort()
        graph, visited = [set() for _ in range(sz)], [False for _ in range(sz)]
        for i in range(sz - 1):
            for j in range(i + 1, sz):
                if math.sqrt(nums[i] + nums[j]) == int(math.sqrt(nums[i] + nums[j])):
                    graph[i].add(j)
                    graph[j].add(i)

        def dfs(cur_idx, count):
            nonlocal sz, res
            if count == sz:
                res += 1
                return
            last_num = -1
            for neighbor in graph[cur_idx]:
                if not visited[neighbor] and nums[neighbor] != last_num:
                    visited[neighbor] = True
                    dfs(neighbor, count + 1)
                    visited[neighbor] = False
                    last_num = nums[neighbor]

        for i in range(sz):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            visited[i] = True
            dfs(i, 1)
            visited[i] = False

        return res


if __name__ == "__main__":
    s = Solution()
