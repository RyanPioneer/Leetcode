"""
Source: https://rb.gy/g6crt
Date: 2023/8/10
Skill:
Ref:
Runtime: 2096 ms, faster than 18.01%
Memory Usage: 24.76 MB, less than 39.19%
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
    def maximumRobots(self, chargeTimes: List[int], runningCosts: List[int], budget: int) -> int:
        lo, hi, sz = 0, len(chargeTimes), len(runningCosts)
        while lo < hi:
            mid, flag = (lo + hi + 1) // 2, True
            running_costs, max_charge_time = runningCosts[0], deque([0])
            for i in range(1, mid):
                running_costs += runningCosts[i]
                while max_charge_time and chargeTimes[i] > chargeTimes[max_charge_time[-1]]:
                    max_charge_time.pop()
                max_charge_time.append(i)
            if chargeTimes[max_charge_time[0]] + mid * running_costs <= budget:
                lo = mid
                continue
            for i in range(mid, sz):
                running_costs += runningCosts[i] - runningCosts[i - mid]
                while max_charge_time and max_charge_time[0] <= i - mid:
                    max_charge_time.popleft()
                while max_charge_time and chargeTimes[i] > chargeTimes[max_charge_time[-1]]:
                    max_charge_time.pop()
                max_charge_time.append(i)
                if chargeTimes[max_charge_time[0]] + mid * running_costs <= budget:
                    lo = mid
                    flag = False
                    break
            if flag:
                hi = mid - 1

        return hi


if __name__ == "__main__":
    s = Solution()
