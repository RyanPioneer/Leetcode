"""
Source: https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/
Date: 2023/4/12
Skill:
Ref:
Runtime: 732 ms, faster than 50%
Memory Usage: 20.1 MB, less than 60.20%
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
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        used_seat, empty_seat, sz = [], [i for i in range(len(times))], len(times)
        heapify(used_seat)
        heapify(empty_seat)
        for i in range(sz):
            times[i].append(i)
        times.sort()

        for i in range(sz):
            start_time, end_time, idx = times[i][0], times[i][1], times[i][2]
            while used_seat and used_seat[0][0] <= start_time:
                released_seat = used_seat[0][1]
                heappop(used_seat)
                heappush(empty_seat, released_seat)
            selected_chair = empty_seat[0]
            heappop(empty_seat)
            heappush(used_seat, (end_time, selected_chair))
            if idx == targetFriend:
                return selected_chair


if __name__ == "__main__":
    s = Solution()
