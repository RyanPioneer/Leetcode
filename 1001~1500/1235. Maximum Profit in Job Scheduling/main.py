"""
Source: https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
Date: 2023/3/19
Skill:
Runtime: 526 ms, faster than 90.71%
Memory Usage: 28.2 MB, less than 53.63%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque, namedtuple
from operator import attrgetter
from heapq import heapify, heappush, heappop, nsmallest
import bisect
import heapq
import functools


class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        jobs, sz = [], len(startTime)
        for i in range(sz):
            jobs.append([startTime[i], endTime[i], profit[i]])
        jobs.sort(key=lambda x: x[1])

        dp1, dp2, res = [-1], [0], 0
        for i in range(sz):
            prev = bisect.bisect_right(dp1, jobs[i][0])
            res = max(res, dp2[prev - 1] + jobs[i][2])
            dp1.append(jobs[i][1])
            dp2.append(res)

        return res


if __name__ == "__main__":
    s = Solution()
    startTime = [1, 2, 3, 3]
    endTime = [3, 4, 5, 6]
    profit = [50, 10, 40, 70]
    res = s.jobScheduling(startTime, endTime, profit)
