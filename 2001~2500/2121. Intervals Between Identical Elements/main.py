"""
Source: https://rb.gy/wbzlh
Date: 2023/7/11
Skill:
Ref:
Runtime: 1532 ms, faster than 15.45%
Memory Usage: 60.2 MB, less than 24.39%
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
    def getDistances(self, arr: List[int]) -> List[int]:
        nums, prev_dis, dis, sz, res = defaultdict(int), defaultdict(int), defaultdict(int), len(arr), []
        for i in range(sz):
            nums[arr[i]] += 1
            dis[arr[i]] += i
        visited = defaultdict(list)
        for i in range(sz):
            num = arr[i]
            if len(visited[num]) == 0:
                dis[num] -= i * nums[num]
                res.append(dis[num])
            else:
                dis[num] -= (i - visited[num][-1]) * nums[num]
                prev_dis[num] += len(visited[num]) * (i - visited[num][-1])
                res.append(dis[num] + prev_dis[num])
            nums[num] -= 1
            visited[num].append(i)
        return res


if __name__ == "__main__":
    s = Solution()
