"""
Source: https://rb.gy/trt37
Date: 2023/7/27
Skill:
Ref:
Runtime: 1690 ms, faster than 40.82%
Memory Usage: 25.82 MB, less than 73.47%
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
    def maxTaskAssign(self, tasks: List[int], workers: List[int], pills: int, strength: int) -> int:
        lo, hi, sz = 0, len(tasks), len(tasks)
        tasks.sort(reverse=True)
        workers.sort()

        def binary_search(num):
            nonlocal sz
            p, local_workers = pills, workers.copy()
            if len(local_workers) < num:
                return False
            for i in range(sz - num, sz):
                if len(local_workers) == 0:
                    return False
                if tasks[i] <= local_workers[-1]:
                    local_workers.pop()
                else:
                    if p == 0:
                        return False
                    else:
                        p -= 1
                        pos = bisect_left(local_workers, tasks[i] - strength)
                        if pos == len(local_workers):
                            return False
                        del local_workers[pos]
            return True

        while lo < hi:
            mid = (lo + hi + 1) // 2
            if binary_search(mid):
                lo = mid
            else:
                hi = mid - 1

        return lo


if __name__ == "__main__":
    s = Solution()
    tasks, workers, pills, strength = [5, 4], [0, 0, 0], 1, 5
    res = s.maxTaskAssign(tasks, workers, pills, strength)
