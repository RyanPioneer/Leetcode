"""
Source: https://leetcode.com/problems/task-scheduler-ii/
Date: 2023/4/7
Skill:
Ref:
Runtime: 890 ms, faster than 96.41%
Memory Usage: 31.2 MB, less than 47.41%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def taskSchedulerII(self, tasks: List[int], space: int) -> int:
        task2day, cur_date = defaultdict(int), 0
        for task in tasks:
            cur_date += 1
            if task not in task2day or cur_date - task2day[task] > space:
                task2day[task] = cur_date
            else:
                cur_date = task2day[task] + space + 1
                task2day[task] = cur_date

        return cur_date


if __name__ == "__main__":
    s = Solution()
